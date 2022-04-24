clear;

year_10=1920:10:1970;
num_10=[105711,123203,131669,150697,179323,203212];

%十年人口增长率
k=@(i)(num_10(i+1)-num_10(i))/(year_10(i+1)-year_10(i));

plot(year_10,num_10,'.-');
hold on;

kn=[];
for i=1:5
    kn=[kn,k(i)];
end

year_5=1925:10:1965;
plot(year_5,kn*100,'o');



    