## How to contribute to NWNX:EE

Thank you for your interest in contributing to NWNX:EE, all contribution are welcome. Please follow the guidelines mentioned below!

### C++ Guidelines
1.  Prefix members variables with m\_.
2.  Use lowerCamelCase for variables.
3.  Use UpperCamelCase for functions.
4.  Use UpperCamelCase for classes.
5.  Use ALL_CAPS for constants and macros.
6.  Braces always start on a new line and always end on a new line.
7.  Spaces, not tabs.
8.  Avoid manual memory management. Use unique_ptr always. This helps transparent hotloading later!

Most importantly, be sure never to manually write memory addresses or hooks yourself. These must ALWAYS go through the core systems to make sure that plugins can play nicely together.

### NWScript Guidelines
We use DoxyGen to automatically generate our documentation, please have a look at existing .nss files to familiarize yourself with the layout of the NWNX:EE NWScript files.
 