*zhengliu  
d1 0 1 diode1  
d2 1 4 diode1  
d3 0 3 diode1  
d4 3 4 diode1  
r3 4 0 10k  
v1 1 3 sin(0 2 100k 0 0)  
e1 ref 0 1 3 1.02  
.tran 0.2u 20u  
.plot tran v(ref) v(4)  
.end