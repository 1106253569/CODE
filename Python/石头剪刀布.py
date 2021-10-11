import random
j1,j2=0,0
i=1
while j1+j2<3:
    print("第{}局".format(i))
    com=random.randint(0,2)
    player=int(input("出拳（石头：0，剪刀：1，布：2）："))
    if (player == 0 and com == 1) or (player==1 and com==2) or (player==2 and com==0):
        print('玩家赢,玩家出拳:%d,电脑出拳:%d'%(player,com))
        j1=j1+1
    elif player==com:
        print("平局")
    else:
        print('电脑赢,玩家出拳:%d,电脑出拳:%d'%(player,com))
        j2=j2+1
    i=i+1
print("Game over")
if(j1>j2):
    print("玩家获胜")
else:
    print("电脑获胜")


    
        
    
    
    