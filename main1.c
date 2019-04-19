apart={}
id={}
ki=[]
def findstu():#打印特定学生信息2
       t=input('请输入要查询学生学号:')
       print("-"*50) 
       print('学号\t姓名\t年龄\t性别\t寝室号')
       for  temp  in  id.keys():
          if temp==t:
              print('%s\t%s\t%s\t%s\t%s'%(t,id[temp][0],id[temp][1],id[temp][2],id[temp][3] ))
          else:
            continue
       print("-"*50)
       end=input('继续查询请输入1/任意键退出:') 
       if end in ['1']:
         findstu()
       else:
         pass
         
def recover():#从文件中提取信息
  global  apart
  global  id
  f=open('fl.json')
  t=open('t1.json')
  content1=f.read()
  content2=t.read()
  apart=eval(content1)
  id = eval(content2)
  f.close ()
  t.close ()
 
def save():  #保存所有x学生的信息
 f=open("fl.json",'w')
 t=open('t1.json','w')
 f.write(str(apart))
 t.write(str(id))
 f.close()
 t.close()
  
def findallstu():     #打印所有学生的信息
    print("-"*50) 
    print('学号\t姓名\t年龄 \t性别\t寝室号')
      
    for  temp  in  id.keys():
          print('%s\t%s\t%s\t%s\t%s'%(temp,id[temp][0],id[temp][1],id[temp][2],id[temp][3] ))
          print("-"*50) 

    
def find():                          # 打印特定寝室的成员信息
   global fi
   while True:
    fi=input('请输入要查询寝室的号码:')
    if fi in['100','101','102','103','104','105']:
        break
    else:
        print('-----------不存在的寝室-----------')
       
        
   b=apart[fi] 
   print("------------------%s寝室人员--------------------"%(fi))                       #得到装有该寝室成员学号的列表
   print("-"*50) 
   print('学号\t姓名\t年龄\t性别\t寝室号')
   for  temp in  b:                    # 遍历出该列表中的所有值
           if id[temp][3]==fi:        # 利用遍历出的值作为id里面的key值，访问学号对应的学生信息
              print('%s\t%s\t%s\t%s\t%s'%(temp,id[temp][0],id[temp][1],id[temp][2],id[temp][3] ))   #按列表打印学生信息
           else:
               pass   
   print("-"*50) 
   end=input('继续查询请输入1/任意键退出:') 
   if end in ['1']:
       find()
   else:
     pass
                  
def exchange():            #学生交换寝室5
    print('-----1.找一个有空位子的寝室------')
    print('-----2.与其他同学交换----------')
           
    
    a=input('请输入数值指令：')
    b=input('请输入需要换寝室学生的学号：')
 
                                                    #判断输入正确的学号
    if b not in id.keys():
           print('----------不存在的学号，请重输----------')
           exchange()

    if a in ['1']:                                    #当学生要从寝室换出时
            for cd  in apart.keys():
                if len(apart[cd])<4:
                  #print(len(apart[cd]))
                  print("还剩下空位的房间有:" ,cd)
                  #else len(apart[cd],len(apart[cd],len(apart[cd],len(apart[cd]=4
                  ki.append(cd)     

            while True: 
               c=input('请输入要进入的寝室：')  
               if c  not  in ki:
                  print('-------请重新选择---------')
                  exchange()
                                  #选择要住进的寝室                         #需要打印信息
               if id[b][3] in ['100','101','102'] and c in ['100','101','102']:     #男生只能在男生的寝室交换
                  break
               elif id[b][3] in ['103','104','105'] and  c in ['103','104','105']:     #女生只能在女生的寝室交换
                  break
               else:
                  pass
                  print('---------男生在100/101/102---------------')
                  print('---------女生在103/104/105---------------')
            apart[c].append(b)                # 在新寝室加入学生学号
            apart[id[b][3]].remove(b)
            id[b][3]=c
            print('----------操作成功-----------')
            print('----------查询请到主界面----------')
           #else:
            #     pass    
    elif a in ['2']:                                        
         print('-----1.你想和某个寝室中的人换------')
         print('-----2.你想与某个同学换---------')
         k=input('请输入数值指令：')
         if k in ['1']:                              #和你想要去的寝室的某人交换
              find()
              while True:
                while True:
                  d=input('请输入列表中你想交换同学的学号:')
                  if d  in id.keys():
                   break
                  else:
                      print('----------请输入正确的学号----------')
                      pass
                if b==d:
                    pass
                    print('----------不能与自己交换----------')   
                elif id[b][3]in['100','101','102'] and  id[d][3] in ['100','101','102']:
                       break
                elif id[b][3] in ['103','104','105']  and  id[d][3] in ['103','104','105']:
                       break     
                else:
                       pass
                       print('---------请输入规定范围内的房间----------')
                       print('---------男生在100/101/102---------------')
                       print('---------女生在103/104/105---------------')
              g=id[b][3]
              q=id[d][3]                            #得到被换这位同学的寝室号
              apart[q].remove(d)              #将这位同学移出该寝室
              apart[g].remove(b) 
              id[d][3]=g                          # 将该同学信息里面的寝室号修改
              apart[q].append(b)              #将需要换寝室的同学加入到该寝室
              id[b][3]=q                           # 修改id
              apart[g].append(d)               #将被换寝室的同学加入新寝室
              print('----------操作成功-----------')
              print('---------查询请到主界面----------')
         elif k in ['2']:           #和同性别的所有人的交换
              findallstu()
              while True:
                while True:
                  d=input('请输入你想交换同学的学号:')
                  if d  in id.keys():
                   break
                  else:
                      print('----------请输入正确的学号----------')
                      pass
                if b==d:
                        pass
                        print('----------不能与自己交换----------')    
                elif id[b][3]in['100','101','102'] and  id[d][3] in ['100','101','102']:
                       break
                elif id[b][3] in ['103','104','105']  and  id[d][3] in ['103','104','105']:
                       break
                else:
                       pass
                       print('---------请输入规定范围内的房间----------')
                       print('---------男生在100/101/102---------------')
                       print('---------女生在103/104/105---------------')
              g=id[b][3]
              q=id[d][3]                            #得到被换这位同学的寝室号
              apart[q].remove(d)              #将这位同学移出该寝室
              apart[g].remove(b) 
              id[d][3]=g                          # 将该同学信息里面的寝室号修改
              apart[q].append(b)              #将需要换寝室的同学加入到该寝室
              id[b][3]=q                           # 修改id
              apart[g].append(d)               #将被换寝室的同学加入新寝室
              print('----------操作成功-----------')
              print('----------查询请到主界面----------')     
         else:
          print('----------输入指令错误，请重输----------')

    else:
       print('----------输入指令错，请重输----------')  
         
            #apart.setdefault(cd,[]).append(b)5
def choose1():
    global  val
    while True:
       val=input("请输入寝室号码100/101/102:")
       if val  not in ['100','101','102']:
           print('----------请在100/101/102中选择----------')
       else: 
        break 
    for  key in  apart.keys():
     if val==key:
          if len(apart[val])>3:
             print('------寝室已满，请重新选择------')
             choose1()
          else:
              pass
             
     else:
         pass     
def choose2():
    import random
    global  val
    val=random.choice(('100','101','102'))
    for  key in  apart.keys():
     if val==key:
          if len(apart[val])>3:
             print('------寝室已满，请重新选择------')
             choose2()
          else:
              pass
              
     else:
         pass
def choose3():#当性别为女，手动选择情况的信息写入11
     global val
     while True:
       val=input("请输入寝室号码103/104/105:")
       if val  not in ['103','104','105']:
           print('----------请在103/104/105中选择----------')
       else: 
        break 
     for  key in  apart.keys():
      if val==key:
          if len(apart[val])>3:
             print('------寝室已满，请重新选择------')
             choose3()
          else:
              pass
             
      else:
         pass
def choose4():#当性别为女，自动选择情况的信息写入++
    import random
    global  val
    val=random.choice(('103','104','105'))
    for  key in  apart.keys():
     if val==key:
          if len(apart[val])>3:
             print('------寝室已满，请重新选择------')
             choose4()
          else:
              pass
     else:
         pass       
def judge():             # 利用 性别 和寝室分配方式把信息有条例地写入字典
    global  sex
    global  room
    global  name
    global   age
    sex=input('请输入学生性别:')
    room=int(input('请选择分配寝室方式[1]随机[2]手动:'))
    if sex=='男' and  room==2:
      choose1()
    elif sex=='男' and  room==1:
      choose2()
    elif sex=='女' and  room==2:
      choose3()
    elif sex=='女' and  room==1:
      choose4()
    else:
        print('--------输入错误，请重输-----')    
        judge()
    message=[name,age,sex,val]
    id[number]=message
    apart.setdefault(val,[]).append(number)
    print('学号    姓名    性别    年龄    寝室号')
    t=number
    for  temp  in  id.keys():
       if temp==t:
          print('%s    %s    %s     %s     %s '%(t,id[temp][0],id[temp][1],id[temp][2],id[temp][3] ))
       else:
         pass

def addstudent():     #添加学生信息
    global  name
    global   age
    global   number
    while True:           # 判断学号是否已经存在，因为学号必须唯一
      print('---学号的应为四位的数字,请按照规范填写---')
      number=input('请输入学号:')
      while len(number)==4 and number.isdigit()==True:
       break
      else:
        pass  
      if number in id.keys():
       print('----------对不起学号已存在，请重新选择学号----------')
      else:
       break     
    name=input('请输入学生姓名:')
    age=input('请输入学生年龄:')
    judge()
def printmeau():                          #系统功能显示块         
 print("-"*40) 
 print('---------学生寝室管理系统----------')
 print('1.录入学生信息及分配寝室')
 print('2.打印各寝室人员表')
 print('3.查看单个学生信息')
 print('4.查看所有学生信息')
 print('5.调整寝室')
 print('6.保存信息到系统')
 print('7.退出系统')
 print('-'*40)
def main():                               #指令的功能选择
  while True:
   printmeau() 
   command=input("请输入命令前的数字:")
   if command in['1']:
      addstudent()
   elif command in['2']:
     find() 
   elif command in['3']:
      findstu() 
   elif command in['4']: 
     findallstu()
   elif  command in['5']:
     exchange()
   elif  command in['6']:
      save()
   elif command in['7']:
    break
   else:
      print('--------不存在的指令---------')
      #main()

recover()
main()
