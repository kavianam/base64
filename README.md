# base64

Implementation of the base64 program based on the [rfc 4648](https://tools.ietf.org/html/rfc4648) written in C. 

In computer science, Base64 is a group of binary-to-text encoding schemes that represent binary data in an ASCII string format by translating it into a radix-64 representation. The term Base64 originates from a specific MIME content transfer encoding. Each Base64 digit represents exactly 6 bits of data. Three 8-bit bytes (i.e., a total of 24 bits) can, therefore, be represented by four 6-bit Base64 digits.
For more info check out the [Wikipedia page](https://en.wikipedia.org/wiki/Base64)

# How to run

`make`

`echo "Hello World" | ./base64`

# Future work

Accept input from either stdin and program arguments.
