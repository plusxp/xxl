	ctx=mkworkspace();
	tmp1=xl(proj(2,&plus,xi(2),0));
	append(ctx,tmp1);
	tmp2=apply(ctx,xi(3));
	XRAY_emit(tmp2);
	ASSERT(_equal(tmp2,xi(5)),"test ctx 0");
	xfree(ctx); xfree(tmp1); xfree(tmp2);

	ctx=mkworkspace();
	tmp1=xl(proj(2,&plus,0,xi(3)));
	append(ctx,tmp1);
	tmp2=apply(ctx,xi(3));
	XRAY_emit(tmp2);
	ASSERT(_equal(tmp2,xi(6)),"test ctx 1");
	xfree(ctx); xfree(tmp1); xfree(tmp2);

	ctx=mkworkspace();
	tmp1=xln(2,proj(2,&plus,0,xi(2)),proj(2,&plus,0,xi(5)));
	append(ctx,tmp1);
	tmp2=apply(ctx,xi(3));
	XRAY_emit(tmp2);
	ASSERT(_equal(tmp2,xi(10)),"test ctx 2");
	xfree(ctx); xfree(tmp1); xfree(tmp2);

	ctx=mkworkspace();
	tmp1=xln(2,xi(2),proj(2,&plus,xi(5),0));
	append(ctx,tmp1);
	tmp2=apply(ctx,xi(3));
	XRAY_emit(tmp2);
	ASSERT(_equal(tmp2,xi(7)),"test ctx 3");
	xfree(ctx); xfree(tmp1); xfree(tmp2);

	ctx=mkworkspace(); // simple unary function application
	tmp1=xl(proj(1,&count,0,0));
	append(ctx,tmp1);
	tmp2=apply(ctx,xi(4));
	XRAY_emit(tmp2);
	ASSERT(_equal(tmp2,xin(4,0,1,2,3)),"test ctx 4");
	xfree(ctx); xfree(tmp1); xfree(tmp2);

	ctx=mkworkspace(); // try applying an index to a function result
	tmp1=xln(2,proj(1,&count,0,0),xi(2));
	append(ctx,tmp1);
	tmp2=apply(ctx,xi(5));
	XRAY_emit(tmp2);
	ASSERT(_equal(tmp2,xi(2)),"test ctx 5");
	xfree(ctx); xfree(tmp1); xfree(tmp2);

	ctx=mkworkspace(); // subexpression
	tmp1=xln(2,proj(2,&plus,xi(2),0),proj(1,&count,0,0));
	append(ctx,tmp1);
	tmp2=apply(ctx,xi(4));
	XRAY_emit(tmp2);
	ASSERT(_equal(tmp2,xin(6,0,1,2,3,4,5)),"test ctx 6");
	xfree(ctx); xfree(tmp1); xfree(tmp2);

	ctx=mkworkspace();
	append(ctx,parsestr("(\"abc\",(\"def\"))"));
	tmp1=apply(ctx,xl0());
	XRAY_emit(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("1+1"));
	tmp1=apply(ctx,0);
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(2)),"test parsestr 0");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("+1"));
	tmp1=apply(ctx,xi(1));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(2)),"test parsestr 1");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("1+x"));
	tmp1=apply(ctx,xi(1));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(2)),"test parsestr 2");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("1+x*2"));
	tmp1=apply(ctx,xi(1));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(4)),"test parsestr 3");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("1+x*2+4"));
	tmp1=apply(ctx,xi(1));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(8)),"test parsestr 4");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("1,2"));
	tmp1=apply(ctx,xi(1));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xin(2,1,2)),"test parsestr 5");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("1,2+x*2+4"));
	tmp1=apply(ctx,xi(1));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xin(2,8,10)),"test parsestr 6");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("2,4 over +"));
	tmp1=apply(ctx,xi(1));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(6)),"test parsestr 6b - adverb over with + ref");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("(2,4) over +"));
	tmp1=apply(ctx,xi(1));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(6)),"test parsestr 7");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("1+(2,3)"));
	tmp1=apply(ctx,xi(1));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xin(2,3,4)),"test parsestr 8");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("(1+2,3)+(2,3)"));
	tmp1=apply(ctx,xi(1));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xin(2,5,6)),"test parsestr 9");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("(1+(2*3))"));
	tmp1=apply(ctx,0);
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(7)),"test parsestr 10");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("/* test */2"));
	tmp1=apply(ctx,0);
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(2)),"test parsestr 11");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("*100 //test"));
	tmp1=apply(ctx,xi(2));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(200)),"test parsestr 12");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("1000 /* test */ * /* x */ (100*100) //test"));
	tmp1=apply(ctx,xi(2));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(10000000)),"test parsestr 13");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("{x*3}"));
	tmp1=apply(ctx,xi(2));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(6)),"test parsestr 14 - x value in closure");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("{3*x}"));
	tmp1=apply(ctx,xi(2));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(6)),"test parsestr 15");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("{*3}"));
	tmp1=apply(ctx,xi(2));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(6)),"test parsestr 16");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("5 {x*y} x"));
	tmp1=apply(ctx,xi(2));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(10)),"test parsestr y in func body");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("{count}"));
	tmp1=apply(ctx,xi(3));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xin(3,0,1,2)),"test parsestr count in func body");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("count+2 each {count}"));
	tmp1=apply(ctx,xi(3));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xln(3,xin(2,0,1),xin(3,0,1,2),xin(4,0,1,2,3))),"test parsestr 18");
	xfree(ctx);xfree(tmp1);

	/*
	 * this test should probably never have passed
	 * it doesnt make sense to resolve 'y' as a variable from scope
	 * think of the chaos that could cause when you intend a projection and you
	 * get a parent scope's ctx value y! i'm disabling this for now
	ctx=mkworkspace();
	tmp1=xd0();
	assign(tmp1,Tt(y),xi(7));
	append(ctx,tmp1);
	append(ctx,parsestr("+y*3"));
	tmp1=apply(ctx,xi(2));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(27)),"test parsestr 19");
	xfree(ctx);xfree(tmp1);
	*/

	ctx=mkworkspace();
	assign(KEYS(ctx),Tt(y),xi(7));
	append(ctx,parsestr("x as 'n * 2 as 'doublen"));
	tmp1=apply(ctx,xi(2));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(4)),"test as 0");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("\"z\""));
	tmp1=apply(ctx,0);
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,entags(xc('z'),"string")),"test parsestr 21");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("\"a\" as 's;s+1"));
	tmp1=apply(ctx,0);
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,entags(xc('b'),"string")),"test as 1");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("[1,2,3]"));
	tmp1=apply(ctx,0);
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xln(3,xi(1),xi(2),xi(3))),"test parsestr list literal 23");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("['a:1]"));
	tmp1=apply(ctx,0);
	XRAY_emit(tmp1);
	ASSERT(_equal(apply(tmp1,Tt(a)),xi(1)),"test parsestr dict literal 24");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("['a:1,'b:2]"));
	tmp1=apply(ctx,0);
	XRAY_emit(repr(tmp1));
	tmp2=xfroms("['a:1, 'b:2]");
	XRAY_emit(tmp1);XRAY_emit(tmp2);
	ASSERT(_equal(repr(tmp1),tmp2),"test parsestr dict literal 25");
	xfree(ctx);xfree(tmp1);xfree(tmp2);

	ctx=mkworkspace();
	ctx=append(ctx,parsestr("[\"aaa\"]"));
	tmp2=apply(ctx,0);
	ctx=append(ctx,parsestr("(\"aaa\")"));
	tmp1=apply(ctx,0);
	XRAY_emit(tmp2);
	XRAY_emit(tmp1);
	// ASSERT(_equal(tmp1,tmp2),"test parsestr string equivalence 0");
	xfree(tmp1);xfree(tmp2);

	ctx=mkworkspace();
	ctx=append(ctx,parsestr("[1,\"aaa\"]"));
	tmp2=apply(ctx,0);
	ctx=append(ctx,parsestr("(1,\"aaa\")"));
	tmp1=apply(ctx,0);
	XRAY_emit(tmp2);
	XRAY_emit(tmp1);
	// ASSERT(_equal(tmp1,tmp2),"test parsestr string equivalence 1");
	xfree(tmp1);xfree(tmp2);

	ctx=mkworkspace();
	append(ctx,parsestr("['a:(1,2),'b:\"barf\"]"));
	tmp1=apply(ctx,0);
	XRAY_emit(tmp1);
	XRAY_emit(repr(tmp1));
	ASSERT(_equal(repr(tmp1),xfroms("['a:(1,2), 'b:\"barf\"]")),"test parsestr dict literal 26");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("('a,'b):((1,2),\"barf\")"));
	tmp1=apply(ctx,0);
	XRAY_emit(tmp1);
	ASSERT(_equal(repr(tmp1),xfroms("['a:(1,2), 'b:\"barf\"]")),"test parsestr dict literal 27");

	ctx=mkworkspace();
	append(ctx,parsestr("5 {x*y} as 'f;3 f")); 
	tmp1=apply(ctx,xi(2));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(15)),"test func as var 1");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("5 {x*y} as 'f;f 3")); // note - technically invalid but still works! nice
	tmp1=apply(ctx,xi(2));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(15)),"test func as var 2");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr(";* as 'f;4 f 6"));  // leading ; disables auto-left-projection of invisible x
	tmp1=apply(ctx,xi(2));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(24)),"test func as var 3");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr(";* as 'xyzzyxyzzy;4 xyzzyxyzzy 6"));  // leading ; disables auto-left-projection of invisible x
	tmp1=apply(ctx,xi(2));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(24)),"test func as var 4 long name");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr(";{x*2}as 'doub;7doub"));
	tmp1=apply(ctx,xi(3));
	XRAY_emit(tmp1);
	ASSERT(_equal(tmp1,xi(14)),"test func as var 4");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr(";{x*y}as 'mul;7mul as 'ms;10ms"));
	tmp1=apply(ctx,xi(3));
	ASSERT(_equal(tmp1,xi(70)),"test func as dyadic var");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("{x*y}as 'mul;7mul"));
	tmp1=apply(ctx,xi(3));
	ASSERT(_equal(tmp1,xi(21)),"test func as dyadic y");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("{x*y}as 'mul;7mul"));
	tmp1=apply(ctx,xi(3));
	ASSERT(_equal(tmp1,xi(21)),"test func as dyadic y");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("[3,4,5]each{+2}"));
	tmp1=apply(ctx,xi(3));
	ASSERT(_equal(tmp1,xln(3,xi(5),xi(6),xi(7))),"test apply simple lambda");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("['q:1,'w:2] as 'd;d"));
	tmp1=apply(ctx,0);
	tmp2=evalstrin("['q:1, 'w:2]", ctx);
	ASSERT(_equal(tmp1,tmp2),"test evalstrin and complex variables");
	xfree(ctx);xfree(tmp1);xfree(tmp2);

	ctx=mkworkspace();
	append(ctx,parsestr("['q:1,'w:2] as 'd;d ! ('w,5)"));
	tmp1=apply(ctx,0);
	tmp2=evalstrin("['q:1, 'w:5]", ctx);
	ASSERT(_equal(tmp1,tmp2),"test amend dict val");
	xfree(ctx);xfree(tmp1);xfree(tmp2);

	ctx=mkworkspace();
	append(ctx,parsestr("['q:1,'w:2] as 'd;d,['w:5]"));
	tmp1=apply(ctx,0);
	tmp2=evalstrin("['q:1, 'w:5]", ctx);
	XRAY_emit(tmp1);XRAY_emit(tmp2);
	ASSERT(_equal(tmp1,tmp2),"test join dict literal");
	xfree(ctx);xfree(tmp1);xfree(tmp2);

	ctx=mkworkspace();
	append(ctx,parsestr(";{x*y}as 'z;7 z 6")); // without the semicolon the system tries to use xl0 as x.. helpfully
	// note: last part above used to read 'z 7 6' but the interpreter was getting
	// confused by the context (z) sometimes being treated as data and sometimes
	// as invokable. the correct syntax to use with z here is 7 z 6, so i've
	// updated it as such. this convenience feature has created a lot of
	// annoyance.
	tmp1=apply(ctx,xl0());
	ASSERT(_equal(tmp1,xi(42)),"test y projection");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("\"a\\\"b\\\"c\r\n\""));
	tmp1=apply(ctx,xl0());
	ASSERT(_equal(tmp1,xcn(7,'a','"','b','"','c',13,10)),"parse quoted string");
	xfree(ctx);xfree(tmp1);

	ctx=mkworkspace();
	append(ctx,parsestr("\"\""));
	tmp1=apply(ctx,0);
	ASSERT(_equal(tmp1,xc0()),"parse empty quoted string");

	tmp1=parsestr("{x*3}"); // returns lambda and repr of auto-included \n; only care about former
	XRAY_emit(tmp1);
	tmp2=ELl(tmp1,0);
	XRAY_emit(tmp2);
	ASSERT(LIST(tmp2) && tmp2->tag==Ti(lambda) && tmp2->n==2 && _equal(ELl(tmp2,1),xi(1)),"test lambda internals 0");
	xfree(ctx);xfree(tmp1);
	XRAY_emit(ctx);XRAY_emit(tmp1);

	tmp1=parsestr("/*{1}*/");
	XRAY_emit(tmp1);
	ASSERT(LIST(tmp1) && ELl(tmp1,0)->tag==Ti(comment) && ELl(tmp1,1)->tag==Ti(ws),"lambda in comment");
	xfree(tmp1);

	tmp1=parsestr("{/*a*/}");
	XRAY_emit(tmp1);
	ASSERT(LIST(tmp1) && ELl(tmp1,0)->tag==Ti(lambda) 
									  && ELl(ELl(ELl(tmp1,0),0),0)->tag==Ti(comment)
									  && ELl(tmp1,1)->tag==Ti(ws),"comment in lambda");
	xfree(tmp1);

VP a,b,c;
c=mkworkspace();
b=parsestr("\n//x\n");
ASSERT(b->n==2 && ELl(b,0)->tag==Ti(ws) && ELl(b,1)->tag==Ti(comment) && ELl(b,1)->n==4,"comment after newline");
xfree(c);xfree(b);

c=mkworkspace();
b=parsestr("\n//x\n\n//y");
ASSERT(b->n==4 && ELl(b,0)->tag==Ti(ws) && ELl(b,1)->tag==Ti(comment) && ELl(b,1)->n==4,"comment after newline part deux");
xfree(c);xfree(b);

c=mkworkspace();
b=parsestr(":a::b::c:");
XRAY_emit(b);
ASSERT(b->n==8 && 
			 ELl(b,0)->tag==Ti(raw) && 
			 ELl(b,1)->tag==Ti(name) && 
			 ELl(b,2)->tag==Ti(oper) && 
			 ELl(b,3)->tag==Ti(name) && 
			 ELl(b,4)->tag==Ti(oper) && 
			 ELl(b,5)->tag==Ti(name) && 
			 ELl(b,6)->tag==Ti(raw), "long oper");
xfree(c);xfree(b);

