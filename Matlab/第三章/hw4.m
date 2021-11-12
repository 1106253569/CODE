clear;
country=80;
city=20;
change=0.05*country-0.01*city;
year=0;
tend=[];
while year<200
    year=year+1;
    city=city+change;
    country=country-change;
    change=0.05*country-0.01*city;
    tend=[tend,city/100];
end
plot(tend);
C=[0.05 -0.01;-0.05 0.01];
D=[20;80];
for i=0:50
    D=D+C*D;
end
D

    
    