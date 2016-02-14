VP d;

c=mkworkspace();
b=evalstrin("(1,2,3,4)@2",c);
ASSERT(_equal(b,xi(3)),"test apply num 0");

c=mkworkspace();
b=evalstrin("1 iftrue 3",c);
ASSERT(_equal(b,xi(3)),"test if 0");
xfree(c);xfree(b);

c=mkworkspace();
b=evalstrin("1 iftrue 3",c);
ASSERT(_equal(b,xi(3)),"test if 0");
xfree(c);xfree(b);

c=mkworkspace();
b=evalstrin("1 iftrue {3}",c);
ASSERT(_equal(b,xi(3)),"test if 0 f");
xfree(c);xfree(b);

c=mkworkspace();
b=evalstrin("1 ifelse (3,2)",c);
ASSERT(_equal(b,xi(3)),"test if 1");
xfree(c);xfree(b);

c=mkworkspace();
b=evalstrin("0 ifelse (3,2)",c);
ASSERT(_equal(b,xi(2)),"test if 2");
xfree(c);xfree(b);

c=mkworkspace();
b=evalstrin("1 ifelse ({x*2},{x*3})",c);
ASSERT(_equal(b,xi(2)),"test if 3");
xfree(c);xfree(b);

c=mkworkspace();
b=evalstrin("[[4,5],[6,7]]@[0,1]",c);
ASSERT(_equal(b,xi(5)),"test apply at depth 0");
xfree(c);xfree(b);

c=mkworkspace();
b=evalstrin("['a:(1,2,3),'b:(4,5,6)]@['b,2]",c);
ASSERT(_equal(b,xi(6)),"test apply at depth in dict");
xfree(c);xfree(b);

c=mkworkspace();
b=evalstrin("777 as 'last;last",c);
d=evalstrin("777 as 'last;.last",c);
DUMP(b);
DUMP(d);
ASSERT(!_equal(b,d) && _equal(b,xi(777)) && _equal(d,x1(&last)), "names derived from root");
xfree(b);xfree(d);xfree(c);

/* 
this doesnt work yet - probably rightfully.. 
c=mkworkspace();
b=evalstrin("(1,2)as 'd;(3,4)as 'e;(d,e)",c);
ASSERT(_equal(b,xin(4,1,2,3,4)),"compound subexpr 0");
xfree(c);xfree(b);
*/

#ifdef STDLIBFILE
c=mkworkspace();
b=evalstrin(".file.get",c);
DUMP(b);
ASSERT(_equal(b,x1(&fileget)),"stdlib file reference");
xfree(c);xfree(b);
c=mkworkspace();
b=evalstrin(". get['file,\"def.h\"]",c);
DUMP(b);
ASSERT(IS_c(b)&&b->n>5000,"stdlib modular get def.h");
xfree(c);xfree(b);
#endif

c=mkworkspace();
b=evalstrin("543 as 'zebra; . get 'zebra",c);
ASSERT(IS_i(b) && AS_i(b,0) == 543,"test . get");
xfree(c);xfree(b);

c=mkworkspace();
b=evalstrin("['abc:100,'xyz:999]each{-1}",c);
a=evalstrin("['abc:99,'xyz:998]",c);
ASSERT(_equal(repr(b),repr(a)),"dict each");

