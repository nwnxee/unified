#!/bin/bash

set -e

ROHOMEPATH=/nwn/home
HOMEPATH=/nwn/run

# Let's make a shadow-copy of home and link us in
echo "[*] Linking in user home"
for p in database hak modules override portraits saves servervault tlk; do
  if [ ! -d $ROHOMEPATH/$p ]; then mkdir -v $ROHOMEPATH/$p; fi
  if [ ! -e $HOMEPATH/$p ]; then ln -vs $ROHOMEPATH/$p $HOMEPATH/; fi
done
for p in dialog.tlk dialogf.tlk; do
  if [ ! -L $HOMEPATH/$p ]; then ln -vs $ROHOMEPATH/$p $HOMEPATH/; fi
done

# Setup read-only copies of nwn and nwnplayer.ini
echo "[*] Importing configuration"
if [ -f $ROHOMEPATH/nwn.ini ]; then
  echo "[*] .. nwn.ini"
  <$ROHOMEPATH/nwn.ini awk -f /nwn/prep-nwn-ini.awk >$HOMEPATH/nwn.ini
fi

if [ -f $ROHOMEPATH/nwnplayer.ini ]; then
  echo "[*] .. nwnplayer.ini"
  <$ROHOMEPATH/nwnplayer.ini awk -f /nwn/prep-nwnplayer-ini.awk >$HOMEPATH/nwnplayer.ini
fi

LOGPID=0
if [ "$NWN_TAIL_LOGS" = "y" ]; then
  echo "[*] Server logs mirrored to stdout"
  (sleep 1; tail -q -F \
    /nwn/run/logs.0/nwserverLog1.txt \
    /nwn/run/logs.0/nwserverError1.txt) &
fi

echo "[*] Port: ${NWN_PORT:-5121}/udp"

# Forward SIGTERM to nwserver-linux
# From: https://unix.stackexchange.com/a/444676
prep_term()
{
    unset term_child_pid
    unset term_kill_needed
    trap 'handle_term' TERM INT
}

handle_term()
{
    if [ "${term_child_pid}" ]; then
        kill -TERM "${term_child_pid}" 2>/dev/null
    else
        term_kill_needed="yes"
    fi
}

wait_term()
{
    term_child_pid=$!
    if [ "${term_kill_needed}" ]; then
        kill -TERM "${term_child_pid}" 2>/dev/null
    fi
    wait ${term_child_pid}
    trap - TERM INT
    wait ${term_child_pid}
}

set +e
prep_term
LD_PRELOAD=$NWN_LD_PRELOAD LD_LIBRARY_PATH=$NWN_LD_LIBRARY_PATH ./nwserver-linux \
  $NWN_EXTRA_ARGS \
  -port ${NWN_PORT:-5121} \
  -interactive \
  -servername "${NWN_SERVERNAME:-I was too lazy to configure my server.}" \
  -module "${NWN_MODULE:-DockerDemo}" \
  -publicserver "${NWN_PUBLICSERVER:-0}" \
  -maxclients "${NWN_MAXCLIENTS:-96}" \
  -minlevel "${NWN_MINLEVEL:-1}" \
  -maxlevel "${NWN_MAXLEVEL:-40}" \
  -pauseandplay "${NWN_PAUSEANDPLAY:-1}" \
  -pvp "${NWN_PVP:-2}" \
  -servervault "${NWN_SERVERVAULT:-1}" \
  -elc "${NWN_ELC:-1}" \
  -ilr "${NWN_ILR:-1}" \
  -gametype "${NWN_GAMETYPE:-0}" \
  -oneparty "${NWN_ONEPARTY:-0}" \
  -difficulty "${NWN_DIFFICULTY:-3}" \
  -autosaveinterval "${NWN_AUTOSAVEINTERVAL:-0}" \
  -playerpassword "${NWN_PLAYERPASSWORD}" \
  -dmpassword "${NWN_DMPASSWORD}" \
  -adminpassword "${NWN_ADMINPASSWORD}" \
  -reloadwhenempty "${NWN_RELOADWHENEMPTY:-0}" &
wait_term
RET=$?
set -e

# If this thing crashed, copy the log to the public home so the user
# can deliberate over it.
if ls $HOMEPATH/nwserver-crash* 1> /dev/null 2>&1; then
  echo "The server crashed with return code "$RET". Trying to save crash data into your mounted server home."
  cp -va $HOMEPATH/nwserver-crash*.log $ROHOMEPATH/ || true
fi
exit $RET
