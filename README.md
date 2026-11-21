SHA-256 Password Hash Matcher (C)
Project Overview
This project is a command-line program written in C that explores password hashing, string manipulation, and character-level search techniques. Given a SHA-256 hash, the program reads possible passwords from standard input and checks whether any candidate produces the same hash. It also tests variations created by changing the case of one ASCII letter at a time, allowing it to find certain capitalization differences without requiring every variation to appear in the input list.

The project demonstrates practical use of the OpenSSL cryptographic library, loops, arrays, string functions, hexadecimal formatting, and basic command-line input handling. It is intended as an educational demonstration of hash comparison rather than a complete password-recovery or security tool.
How the Code Works
The check_sha256() function uses OpenSSL's SHA256() function to calculate a 32-byte digest for a candidate password. It converts the digest into a 64-character hexadecimal string, compares that string with the supplied hash using strcasecmp(), and increments a counter that tracks hashing operations.

The main() function accepts the target hash as a command-line argument and reads candidate passwords one line at a time using fgets(). It removes each line's trailing newline, copies the password into a temporary buffer, and individually switches uppercase letters to lowercase or lowercase letters to uppercase. Each modified candidate is hashed and compared. The program also checks the original password. When it finds a match, it prints the matching password and stops searching; otherwise, it prints a no-match message after reaching the end of the input.

Compile and run (requires a C compiler and OpenSSL development libraries. )
on most Linux systems and MacOS
gcc *.c -o pwcrack -lcrypto
./pwcrack a2c3b02cb22af83d6d1ead1d4e18d916599be7c2ef2f017169327df1f7c844fd
