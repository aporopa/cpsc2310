comment(`Abigail Poropatich')
comment(`CPSC 2310 - 001')
comment(`Binary to Decimal conversion')
comment(`26 May 2023')


comment(`Variable definitions')
word(N, 1001)
word(decimal, 0)    
word(power, 1)      
word(two, 2)
word(done, 0) 
word(ten, 10)
word(neg, -1)    

label(start)
    load(N)
    ble0(done)

label(loop)
                    comment(`Performing modulus division')
    div(ten)
    mul(ten)
                    comment(`Extracting the first value and multiplying to positive')
    sub(N)
    mul(neg)
    mul(power)
                    comment(`Adding and storing the decimal value')
    add(decimal)
    store(decimal)

                    comment(`Updating the power')
    load(power)
    mul(two)
    store(power)
                    
                    comment(`Updating N for the next iteration')
    load(N)
    div(ten)
    store(N)

                    comment(`N > 0')
    bgt0(loop)

label(done)
    print(decimal)
    halt

    end(start)
