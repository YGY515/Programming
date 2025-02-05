# 묵찌빠 - 2019 작성


import random
user = 0
com = 0
win = 0
same = 0

print("컴퓨터와 묵찌빠를 해 봅시다!") # 게임 시작 멘트-가위바위보
print("그 전에 먼저 컴퓨터와 가위바위보를 해볼까요?")
print("가위, 바위, 보 중 하나를 입력해주세요!")

print("\n")

while True: # 가위바위보 변수 저장
    x=str(input("나: "))
    n=random.choice(["가위","바위","보"])

    if n == "가위":
        com = 1
    elif n == "바위":
        com = 2
    elif n == "보":
        com = 3

    if x == "가위" or x == "바위" or x == "보":
        if x == "가위":
            user = 1
            print("컴퓨터:",n)
        
        elif x == "바위":
            user = 2
            print("컴퓨터:",n)
        
        elif x == "보":
            user = 3
            print("컴퓨터:",n)

    else:
        print("컴퓨터:...엥?")


    if x == n:
        print("비겼습니다. 다시 한번 입력해주세요.")
    else:
        break

print("\n")

while True: # 가위바위보 결과
    if (user==1 and com==3) or (user==2 and com==1) or (user==3 and com==2):

        print("컴퓨터: 히잉")
        print("당신이 이겼습니다. 바로 묵찌빠 게임을 시작해 볼까요.")
        print("묵, 찌, 빠 중 하나를 입력해주세요.")
        win = 1
        if user==1:
            print("나: 찌..찌...")
            break
        elif user==2:
            print("나: 묵..묵...")
            break
        elif user==3:
            print("나: 빠..빠...")
            break
        

    if (com==1 and user==3) or (com==2 and user==1) or (com==3 and user==2):

        print("컴퓨터: 아싸!")
        print("당신이 졌습니다. 바로 묵찌빠 게임을 시작해 볼까요.")
        print("묵,찌,빠 중 하나를 입력해주세요.")
        win = 0
        if com==1:
            print("컴퓨터: 찌..찌...")
            break
        elif com==2:
            print("컴퓨터: 묵..묵...")
            break
        elif com==3:
            print("컴퓨터: 빠..빠...")
            break
        
print("\n")


while True: # 묵찌빠 변수 저장
    x=str(input("나: "))
    n=random.choice(["묵","찌","빠"])

    if n == "찌":
        com = 1
    elif n == "묵":
        com = 2
    elif n == "빠":
        com = 3
    
    if x == "찌":
        user = 1
    elif x == "묵":
        user = 2
    elif x == "빠":
        user = 3
    else:
         print("컴퓨터: 제대로 입력하게나")

    # 결과 판단
    if (user==1 and com==3) or (user==2 and com==1) or (user==3 and com==2):
        win = 1 # 사용자가 이겼을 때

    elif (user==3 and com==1) or (user==1 and com==2) or (user==2 and com==3):
        win = 0 # 컴퓨터가 이겼을 때

    elif (com==1 and user==1) or (com==2 and user==2) or (com==3 and user==3):
        same = 1 # 둘 다 같은 것을 냈을 때
        
 
    if com == 1:
        print("컴퓨터: ..찌!\n")

    elif com == 2:
        print("컴퓨터: ..묵!\n")
            
    elif com == 3:
        print("컴퓨터: ..빠!\n")

    if same == 1:
        if win == 1: # 사용자가 이겼을 때 + 컴터가 같은 것을 냈을 때
            print("컴퓨터: 히잉")
            print("당신이 이겼습니다. 컴퓨터를 상대로 잘도 하셨군요. 축하합니다!")
            break
        elif win == 0: # 컴퓨터가 이겼을 때 + 사용자가 같은 것을 냈을 때
            print("컴퓨터: 이겼드아아!!")
            print("당신은 졌습니다. 역시 컴퓨터를 이길수가 없죠잉~")
            break


    if win == 1:
        print("나:",x,"...",x)
        
    elif win == 0:
        print("컴퓨터:",n,"...",n)

    
        
input()
