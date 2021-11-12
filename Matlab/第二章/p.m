function T=p(x,y)
    if x+y>1
        T=0.5457*exp(-0.75*y^2-3.75*x^2-1.5*x);
    elseif x+y<=-1
        T=0.5457+exp(-0.75*y^2-3.75*x^2-1.5*x);
    else
        T=0.575*exp(-1*y^2-6*x^2);
    end
end

