#ifndef _bitwise_h_
#define _bitwise_h_

#define logicalOne 1

//Sets bit xth bit in n as 1
#define bitw_set(n,x) n |= logicalOne << x

//Sets bit xth bit in n as 0
#define bitw_clear(n,x) n &= ~(logicalOne << x);

//Inverses xth bit in n
#define bitw_inverse(n,x) n ^= logicalOne << x

//Gets xth bit in n
#define bitw_bit(n,x) ((n >> x) & logicalOne)

//Sets xth bit in n to b
#define bitw_sset(n,x,b) n ^= (- b ^ n) & (logicalOne << x)

#define bitw_toInt16(l,h) (uint16_t)(l << 8 | h)

#endif
