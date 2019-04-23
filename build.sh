gcc -c -Wall -Werror -fpic src/jlstd.c -o obj/jlstd.o
gcc -shared -o bin/libjlstd.so obj/jlstd.o
# Needs root to install, so sudo.
# Install Binary
cp bin/libjlstd.so /usr/local/lib
chmod 0755 /usr/local/lib/libjlstd.so
ldconfig
unset LD_LIBRARY_PATH
echo "Binary Installed To: /usr/local/lib/libjlstd.so"
# Install Headers
cp -r include/jlstd /usr/include
echo "Headers Installed To: /usr/include/jlstd"
