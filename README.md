Current API: 8154

Build instructions:

- mkdir build
- cd build
- cmake -DCMAKE_BUILD_TYPE=Release ../
- make -j 8

Dependencies

- Linux requires GCC 6.4.0+ (?) or Clang 3.8+ (?). Something modern for sure. Note that if you compile on Clang in debug mode you will segfault -- it generates incorrect assembly for the API jumps. Release mode works fine.
- Windows status is UNKNOWN. It will probably compile if given an API, but it will break at run-time.

Docker Build Instructions (Build for Linux using the pre-configured NWNX Docker builder):

- Build on Linux, MacOS, or Docker-Toolbox
	- Execute ./scripts/rundockerbuild.sh
		- The script will pull the NWNX Linux Docker builder image
		- The Container will execute the ./scripts/buildnwnx.sh script
		- To perform a clean and build pass -c eg './scripts/rundockerbuild.sh -c'
- Build on Windows
	- Execute ./scripts/rundockerbuild.ps1
		- The script will pull the NWNX Linux Docker builder image
		- The Container will execute the ./scripts/buildnwnx.sh script
		- To perform a clean and build pass -FORCECLEAN eg './scripts/rundockerbuild.ps1 -FORCECLEAN'

Contribution guide:

- If you're making changes to the core, please follow the existing code style guide and code quality guide below.
- If you're submitting a plugin, do whatever you want, as long as you use the core services for your stuff when appropriate.

Core code style guide:

- Prefix members variables with m_.
- Use lowerCamelCase for variables.
- Use UpperCamelCase for functions.
- Use UpperCamelCase for classes.
- Use ALL_CAPS for constants and macros.
- Braces always start on a new line and always end on a new line.
- Spaces, not tabs.
- Avoid manual memory management. Use unique_ptr always. This helps transparent hotloading later!

Core code quality guide:

- Code with all possible platforms in mind.
- Code with transparent hotswappability in mind.
- Code with ease of use of developers in mind.
- Generally, please try to any platform-specific code in NWNXLib contained within the Platform namespace.
