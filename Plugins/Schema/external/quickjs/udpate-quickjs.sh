#!/bin/bash
# Self-healing: Strip Windows line endings if running on Unix/macOS/Docker
[[ "$OSTYPE" == "linux-gnu"* || "$OSTYPE" == "darwin"* ]] && sed -i 's/\r$//' "$0" 2>/dev/null
# Standard Windows fix for Git Bash
sed -i 's/\r$//' "$0" 2>/dev/null

set -e

# OS-Aware Path Conversion Prevention
if [[ "$OSTYPE" == "msys" || "$OSTYPE" == "cygwin" ]]; then
    export MSYS_NO_PATHCONV=1
fi

cd "$(dirname "$0")"
TARGET_DIR="./src"
mkdir -p "$TARGET_DIR"

echo "Syncing all QuickJS-NG engine files..."

node <<'EOF'
const https = require('https');
const fs = require('fs');
const path = require('path');

const REPO = "quickjs-ng/quickjs";
const BRANCH = "master";
const TARGET_DIR = "./src";

// Fragments to hide the URL from Git Bash path conversion
const p = "htt" + "ps";
const h = "raw." + "github" + "usercontent" + ".com";
const apiH = "api." + "github" + ".com";

async function getFileList() {
    return new Promise((resolve, reject) => {
        const options = {
            hostname: apiH,
            path: `/repos/${REPO}/contents?ref=${BRANCH}`,
            headers: { 'User-Agent': 'Mozilla/5.0' }
        };
        https.get(options, (res) => {
            let data = '';
            res.on('data', (chunk) => data += chunk);
            res.on('end', () => {
                if (res.statusCode !== 200) return reject(new Error(`API ${res.statusCode}`));
                const files = JSON.parse(data)
                    .filter(f => f.type === 'file' && f.name.match(/\.(c|h|js)$/))
                    .map(f => f.name);
                resolve(files);
            });
        }).on('error', reject);
    });
}

async function download(file) {
    return new Promise((resolve, reject) => {
        const url = p + "://" + h + "/" + REPO + "/" + BRANCH + "/" + file;
        const filePath = path.join(TARGET_DIR, file);

        https.get(url, (res) => {
            if (res.statusCode !== 200) return reject(new Error(`HTTP ${res.statusCode} for ${file}`));
            const stream = fs.createWriteStream(filePath);
            res.pipe(stream);
            stream.on('finish', () => {
                stream.close();
                console.log(`  + ${file}`);
                resolve();
            });
        }).on('error', reject);
    });
}

(async () => {
    try {
        const files = await getFileList();
        console.log(`Found ${files.length} files. Downloading...`);
        for (const f of files) { await download(f); }
        console.log("--- Sync Complete ---");
    } catch (e) {
        console.error("Critical Error: " + e.message);
        process.exit(1);
    }
})();
EOF
