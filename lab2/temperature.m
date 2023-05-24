comment(`Abigail Poropatich')
comment(`CPSC 2310 001')
comment(`Lab 2: Java Virtual Machine')
comment(`25 May 2023')

comment(`Local_1 is Celsius and Local_2 is Fahrenheit')

                comment(`Initialize Celsius and Fahrenheit to -40 and store it')
bipush(-40)
istore_1
bipush(-40)
istore_2

label(loop)

iconst_1
invokevirtual(1)

                comment(`Conversion values and operators for C to F via stack')
iload_1
bipush(9)
imul
bipush(5)
idiv
bipush(32)
iadd
istore_2        comment(`Storing the Fahrenheit result')

iconst_2
invokevirtual(2)

iinc(1,10)      comment(`increment by 10')

iload_1
bipush(120)     comment(`120 boundary')
isub

ifle(loop)

return
