#ifndef _bitwise_h_
#define _bitwise_h_

#define logicalOne 1

//Set bit xth bit in n as 1
#define bitw_set(n,x) n |= logicalOne << x

//Set bit xth bit in n as 0
#define bitw_clear(n,x) n &= ~(logicalOne << x);

//Inverse xth bit in n
#define bitw_inverse(n,x) n ^= logicalOne << x

//Get xth bit in n
#define bitw_bit(n,x) (n >> x) & logicalOne

#define bitw_sset(n,x,b) n ^= (- b ^ n) & (logicalOne << x)

#endif
