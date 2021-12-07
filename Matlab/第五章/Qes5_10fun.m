function d=Qes5_10fun(fname,a,h0,e)
    h=h0;
    d=(feval(fname,a+h)-2*feval(fname,a)+feval(fname,a-h))/(h*h);
    d0=d+2*e;
    while abs(d-d0)>e
        d0=d;
        h0=h;
        h=h0/2;
        d=(feval(fname,a+h)-2*feval(fname,a)+feval(fname,a-h))/(h*h);
    end
end

