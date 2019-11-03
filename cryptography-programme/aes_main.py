#python 3



def m14(bt):
    #print(hex(Mul2(hex(Mul2(bt)^int(bt,16))[2:])^int(bt,16))[2:])
    a=Mul2(hex(Mul2(hex(Mul2(bt)^int(bt,16))[2:])^int(bt,16))[2:])
    return a
def m11(bt):
    return(Mul2(hex(Mul2(hex(Mul2(bt))[2:])^int(bt,16))[2:])^int(bt,16))
def m13(bt):
    return(Mul2(hex(Mul2(hex(Mul2(bt)^int(bt,16))[2:]))[2:])^int(bt,16))
def m9(bt):
    return(Mul2(hex(Mul2(hex(Mul2(bt))[2:]))[2:])^int(bt,16))
def main():
    #print("main called")
    h=enc()
    dec(h);

def enc():
    #yet
    hexkey="5468617473206d79204b756e67204675"
    pt="54776F204F6E65204E696E652054776F"
    blockpt=getBlockPt(pt)
    roundkey=key_gen(hexkey)   
    #print(len(roundkey))
    nurounds=10
    for block in blockpt:
        #preroundTransform(block)
        block=addRoundKey(block,roundkey[0])
        for i in range(1,nurounds):
            print(str(i)+"th\n")
            block=encRound(block,roundkey[i])
            print("\n\n\n\n\n")
        print("final")
        block=encFinalRound(block,roundkey[nurounds])
        print(block)
    print("encryption complete")
    return block

def dec(h):
    hexkey="5468617473206d79204b756e67204675"
    pt=h
    blockpt=getBlockPt(pt)
    roundkey=key_gen(hexkey)   
    #print(len(roundkey))
    nurounds=10
    for block in blockpt:
        #preroundTransform(block)
        block=addRoundKey(block,roundkey[10])
        for i in range(0,(nurounds-1)):
            print(str(i+1)+"th\n")
            block=dencRound(block,roundkey[9-i])
            print("\n\n\n\n\n")
        print("final")
        block=dencFinalRound(block,roundkey[0])
        print(block)
    print("decryption complete")
   
def encFinalRound(block,roundkey):
    printstate(blockState(block))
    block=subByte(block)
    print("sub byte")
    printstate(blockState(block))
    block=shiftRows(block)
    print("shift row output")
    printstate(blockState(block))
    print("add round col ")
    block=addRoundKey(block,roundkey)
    printstate(blockState(block))
    return(block)
def dencFinalRound(block,roundkey):
    printstate(blockState(block))
    block=invshiftRows(block)
    print("invshift row output")
    printstate(blockState(block))
    block=subBytesInv(block)
    print("invsub byte")
    printstate(blockState(block))
    print("sdgfg")
    
    print("add round col ")
    block=addRoundKey(block,roundkey)
    printstate(blockState(block))
    return(block)

def encRound(block,roundkey):
    #yet
    
    #printstate(blockState(block))
    print(block)
    block=subByte(block)
    print("sub byte")
    printstate(blockState(block))
    #print(block)
    block=shiftRows(block)
    print("shift row output")
    #print(block)
    printstate(blockState(block))
    print("mix col ")
    block=mixColumns(block)
    #print(block)
    printstate(blockState(block))
    print("add round col ")
    block=addRoundKey(block,roundkey)
    #print(block)
    printstate(blockState(block)) 
    return(block)
def dencRound(block,roundkey):
    #yet
    
    #printstate(blockState(block))
   # print(block)
    block=invshiftRows(block)
    print("invshift row output")
    printstate(blockState(block))
    block= subBytesInv(block)
    print("INVsub byte")
    printstate(blockState(block))
    #print(block)
    
    #print(block)
    #printstate(blockState(block))
    print("add round col ")
    block=addRoundKey(block,roundkey)
    #print(block)
    printstate(blockState(block)) 
    print("invmix col ")
    print(block)
    block=blockState(block)
   
    block=invmixColumns(block)
    #print(block)
    printstate(blockState(block))
    
   
    return(block)

""" def subByte(block):
    #yet
    return (block) """


def subByte(state):
    #print(state)
    stateHex=[]
    sbox = [
        ["63", "7c", "77", "7b", "f2", "6b", "6f", "c5", "30", "01", "67", "2b", "fe", "d7", "ab", "76"],
        ["ca", "82", "c9", "7d", "fa", "59", "47", "f0", "ad", "d4", "a2", "af", "9c", "a4", "72", "c0"],
        ["b7", "fd", "93", "26", "36", "3f", "f7", "cc", "34", "a5", "e5", "f1", "71", "d8", "31", "15"],
        ["04", "c7", "23", "c3", "18", "96", "05", "9a", "07", "12", "80", "e2", "eb", "27", "b2", "75"],
        ["09", "83", "2c", "1a", "1b", "6e", "5a", "a0", "52", "3b", "d6", "b3", "29", "e3", "2f", "84"],
        ["53", "d1", "00", "ed", "20", "fc", "b1", "5b", "6a", "cb", "be", "39", "4a", "4c", "58", "cf"],
        ["d0", "ef", "aa", "fb", "43", "4d", "33", "85", "45", "f9", "02", "7f", "50", "3c", "9f", "a8"],
        ["51", "a3", "40", "8f", "92", "9d", "38", "f5", "bc", "b6", "da", "21", "10", "ff", "f3", "d2"],
        ["cd", "0c", "13", "ec", "5f", "97", "44", "17", "c4", "a7", "7e", "3d", "64", "5d", "19", "73"],
        ["60", "81", "4f", "dc", "22", "2a", "90", "88", "46", "ee", "b8", "14", "de", "5e", "0b", "db"],
        ["e0", "32", "3a", "0a", "49", "06", "24", "5c", "c2", "d3", "ac", "62", "91", "95", "e4", "79"],
        ["e7", "c8", "37", "6d", "8d", "d5", "4e", "a9", "6c", "56", "f4", "ea", "65", "7a", "ae", "08"],
        ["ba", "78", "25", "2e", "1c", "a6", "b4", "c6", "e8", "dd", "74", "1f", "4b", "bd", "8b", "8a"],
        ["70", "3e", "b5", "66", "48", "03", "f6", "0e", "61", "35", "57", "b9", "86", "c1", "1d", "9e"],
        ["e1", "f8", "98", "11", "69", "d9", "8e", "94", "9b", "1e", "87", "e9", "ce", "55", "28", "df"],
        ["8c", "a1", "89", "0d", "bf", "e6", "42", "68", "41", "99", "2d", "0f", "b0", "54", "bb", "16"]
        ]
    for i in range(0,len(state),2):
        stateHex.append(sbox[int(state[i],16)][int(state[i+1],16)])
    return ("".join(stateHex))
    

def subBytesInv(state):
    stateSubHex=[]
    sboxInv = [
        ["52", "09", "6a", "d5", "30", "36", "a5", "38", "bf", "40", "a3", "9e", "81", "f3", "d7", "fb"],
        ["7c", "e3", "39", "82", "9b", "2f", "ff", "87", "34", "8e", "43", "44", "c4", "de", "e9", "cb"],
        ["54", "7b", "94", "32", "a6", "c2", "23", "3d", "ee", "4c", "95", "0b", "42", "fa", "c3", "4e"],
        ["08", "2e", "a1", "66", "28", "d9", "24", "b2", "76", "5b", "a2", "49", "6d", "8b", "d1", "25"],
        ["72", "f8", "f6", "64", "86", "68", "98", "16", "d4", "a4", "5c", "cc", "5d", "65", "b6", "92"],
        ["6c", "70", "48", "50", "fd", "ed", "b9", "da", "5e", "15", "46", "57", "a7", "8d", "9d", "84"],
        ["90", "d8", "ab", "00", "8c", "bc", "d3", "0a", "f7", "e4", "58", "05", "b8", "b3", "45", "06"],
        ["d0", "2c", "1e", "8f", "ca", "3f", "0f", "02", "c1", "af", "bd", "03", "01", "13", "8a", "6b"],
        ["3a", "91", "11", "41", "4f", "67", "dc", "ea", "97", "f2", "cf", "ce", "f0", "b4", "e6", "73"],
        ["96", "ac", "74", "22", "e7", "ad", "35", "85", "e2", "f9", "37", "e8", "1c", "75", "df", "6e"],
        ["47", "f1", "1a", "71", "1d", "29", "c5", "89", "6f", "b7", "62", "0e", "aa", "18", "be", "1b"],
        ["fc", "56", "3e", "4b", "c6", "d2", "79", "20", "9a", "db", "c0", "fe", "78", "cd", "5a", "f4"],
        ["1f", "dd", "a8", "33", "88", "07", "c7", "31", "b1", "12", "10", "59", "27", "80", "ec", "5f"],
        ["60", "51", "7f", "a9", "19", "b5", "4a", "0d", "2d", "e5", "7a", "9f", "93", "c9", "9c", "ef"],
        ["a0", "e0", "3b", "4d", "ae", "2a", "f5", "b0", "c8", "eb", "bb", "3c", "83", "53", "99", "61"],
        ["17", "2b", "04", "7e", "ba", "77", "d6", "26", "e1", "69", "14", "63", "55", "21", "0c", "7d"]]


    for i in range(0,len(state),2):
         stateSubHex.append(sboxInv[int(state[i],16)][int(state[i+1],16)])
    return ("".join(stateSubHex))
    



def shiftRows(block):
    #yet to be done
    elmntsz=2
    stater=4
    statec=4
    statemat= [[block[elmntsz*(i+j*statec):elmntsz*(i+j*statec+1)] for j in range(statec)] for i in range(stater)]
    x=statemat
    for i in range(4):
        if i==0:
            pass
        else:
            for k in range(i):
                t=x[i][0]
                for j in range(4):
                    if((j+1)<4):
                       x[i][j]=x[i][j+1]
                x[i][j]=t
    print(x)
    jk=""
    for i in range(4):
        for j in range(4):
            jk=jk+x[j][i]
    print (jk)

    return jk
def invshiftRows(block):
    #yet to be done
    elmntsz=2
    stater=4
    statec=4
    statemat= [[block[elmntsz*(i+j*statec):elmntsz*(i+j*statec+1)] for j in range(statec)] for i in range(stater)]
    print(statemat)
    x=statemat
    for i in range(4):
        if i==0:
            pass
        else:
            for k in range(i):
                t=x[i][3]
                for j in range(1,4):
                    if((j)<4):
                       x[i][4-j]=x[i][4-j-1]
                x[i][0]=t
    print("x vala ")
    print(x)
    jk=""
    for i in range(4):
        for j in range(4):
            jk=jk+x[j][i]
    print (jk)

    return jk
""" def mixColumns(block):
    #yet
    return (block) """
def Mul1(st):
    return int(st,16)

def Mul2(st):
    #print(st)
    #print(int(st,16))
    
    if len(bin(int(st,16)))<10:
        return (2*int(st,16))
    else:
        b=bin(int(st,16))
        w=[]
        b=b[2:10]
        for i in b:
            w.append(i)
        for i in range(7):
            w[i]=w[i+1]
        w[7]='0'
        u=''.join(w)
        return((int(u,2)^int('00011011',2)))


def Mul3(st):
    return (Mul2(st)^int(st,16))
       
def invmixColumns(x):
    consMatInv=[[14,11,13,9],[9 ,14 ,11 ,13],[13, 9, 14, 11],[11 ,13 ,9, 14]]
    w=[] 
    for i in range(4):
        q=[]
        for j in range(4):
            r=0
            for t in range(4):
                
                y=consMatInv[i][t]
                if y==9:
                    r=r^m9(x[t][j])
                    
                elif y==11:
                    r=r^m11(x[t][j])
                    
                elif y==13:
                    r=r^m13(x[t][j])
                else:
                    r=r^m14(x[t][j])
            q.append(hex(r))
        w.append(q)
    for i in range(4):
        for j in range(4):
            w[i][j]=w[i][j][2:4]
    for i in range(4):
        for j in range(4):
            if(len(w[i][j])<2):
                w[i][j]='0'+w[i][j]
    w=stateBlock(w)
    return w
def mixColumns(block):
    consMat=[[2,3,1,1],[1 ,2 ,3 ,1],[1, 1, 2, 3],[3 ,1 ,1, 2]]
    #print("mai hun")
    #print(block)
    k=blockState(block)
    #print("hii")
    #print(k)
    k=[list(i) for i in zip(*k)]
    #print("bye")
    #print(k)
    w=[] 
    for i in range(4):
        q=[]
        for j in range(4):
            r=0
            for t in range(4):
                
                y=consMat[i][t]
                if y==1:
                    r=r^Mul1(k[j][t])
                elif y==2:
                    r=r^Mul2(k[j][t])
                else:
                    r=r^Mul3(k[j][t])
            q.append(hex(r))
        q=hexListStr(q,2)
        w.append(q)
    w=stateBlock(w)
    #print("mai tha")
    #print(w)
    return w

  
def hexListStr(l,n):#n= number of hexadecimals must be present
    l=[str(i) for i in l]
    #print(l)
    l=[ ("0"*(n-len(i[2:])))+i[2:] for i in l]
    #print(l)
    return l


def hexStr(l,n):#n= number of hexadecimals must be present l is hex 
    l=str(l)
    l=(("0"*(n-len(l[2:]))+l[2:]))
    #print(l)
    return(l)

def addRoundKey(block,key):
    block1=list(block)
    key=list(key)
    block1=[int(x,16) for x in block1]
    key=[int(x,16) for x in key]
    for i in range(len(block1)):
       block1[i]=block1[i]^key[i]
    block1=[hex(x)[2:] for x in block1]
    block="".join(map(str,block1)) #state1 has the final addRoundKey value
    return (block)
"""
def preroundTransform(block):
    #yet
    return(block) 












"""   
def rotword(w,q):
    #w=w[2:]
    #print("rot word:"+w)
    
    l=[]
    for j in w:
        l.append(j)
    
    for j in range(2):
        t=l[0]
        for k in range(len(l)):
            if((k+1)<len(l)):
                l[k]=l[k+1]
        l[k]=t 

    #print("list:"+str(l)) 
    yu=""
    for k in l:
        yu=yu+k

    o=subword(l,q)
    #o=xor1(yu,q) 
    return o 

def subword(l,q):
  sub=[
      ["63",   "7c",   "77",     "7b",     "f2",     "6b",     "6f" ,    "c5",     "30",     "01",     "67" ,    "2b",     "fe" ,    "d7",     "ab",     "76"],
     ["ca",     "82",     "c9",     "7d",     "fa",     "59",     "47",     "f0",     "ad",     "d4",     "a2",     "af",     "9c",     "a4",     "72",     "c0"],
     ["b7",     "fd",     "93",     "26",     "36",     "3f",     "f7",     "cc",     "34",     "a5",     "e5",     "f1",     "71",     "d8",     "31",     "15"],
     ["04",     "c7",     "23",     "c3",     "18",     "96",     "05",     "9a",     "07",     "12",     "80",     "e2",     "eb",     "27",     "b2",     "75"],
     ["09",     "83",     "2c",     "1a",     "1b",     "6e",     "5a",     "a0",     "52",     "3b",     "d6",     "b3",     "29",     "e3",     "2f",     "84"],
     ["53"  ,   "d1",     "00",     "ed",     "20",     "fc",     "b1",     "5b",     "6a",     "cb",     "be",     "39",     "4a",     "4c",     "58",     "cf"],
     ["d0",     "ef",     "aa",     "fb",     "43",     "4d",     "33",     "85",     "45",     "f9",     "02",     "7f",     "50",     "3c",     "9f",     "a8"],
     ["51",     "a3",     "40",     "8f",     "92",     "9d",     "38",     "f5",     "bc",     "b6",     "da",     "21",     "10",     "ff",     "f3",     "d2"],
     ["cd",     "0c",     "13",     "ec",     "5f",     "97",     "44",     "17",     "c4",     "a7",     "7e",     "3d",     "64",     "5d",     "19",     "73"],
     ["60",     "81",     "4f",     "dc",     "22",     "2a",     "90",     "88",     "46",     "ee",     "b8",     "14",     "de",     "5e",     "0b",     "db"],
     ["e0",     "32",     "3a",     "0a",     "49",     "06",     "24",     "5c",     "c2",     "d3",     "ac",     "62",     "91",     "95",     "e4",     "79"],
     ["e7",     "c8",     "37",     "6d",     "8d",     "d5",     "4e",     "a9",     "6c",     "56",     "f4",     "ea",     "65",     "7a",     "ae",     "08"],
     ["ba",     "78",     "25",     "2e",     "1c",     "a6",     "b4",     "c6",     "e8",     "dd",     "74",     "1f",     "4b",     "bd",     "8b",     "8a"],
     ["70"    , "3e",     "b5",     "66",     "48",     "03",     "f6",     "0e",     "61",     "35",     "57",     "b9",     "86",     "c1",     "1d",     "9e"],
     ["e1",     "f8",     "98",     "11",     "69",     "d9",     "8e",     "94",     "9b",     "1e",     "87",     "e9",     "ce",     "55",     "28",     "df"],
     ["8c",     "a1",     "89",     "0d",     "bf",     "e6",     "42",     "68",     "41",     "99",     "2d",     "0f",     "b0",     "54",     "bb",     "16" ]  ]
  out=""
  lop=0
  i=0
  for j in range(4):
      a=int(l[i],16)
      i=i+1
     # print("a is : "+str(a))
      b=int(l[i],16)
      i=i+1
      #print("b is : "+str(b))
      out=out+sub[a][b]
     # print(sub[a][b])
      #print("specl"+str(len(sub))+" "+str(len(sub[a])))
  p=xor1(out,q)
 # print("out   :"+out)
  return p 
      

def xor1(out,i):
    rcon=["01000000","02000000","04000000","08000000","10000000","20000000","40000000","80000000","1b000000","36000000"]
    l=int(rcon[(i//4)-1],16)
    x=int(out,16)
    g=l^x
    return g 



def key_gen(cipher_key):
    sz=8
    key=[]
    w=[cipher_key[i*sz:(i+1)*sz] for i in range(len(cipher_key)//sz)]
    #print(w)
    for i in range(44):
        if i<4:
            pass
        else:
            
            if i%4==0:
                t=rotword(w[i-1],i)
                p=int(w[i-4],16)
                l=p^t
                c=hexStr(str(hex(l)),8)
                #c=c[2:]
                w.append(str(c))
            else:
                r=int(w[i-1],16)
                d=int(w[i-4],16)
                s=hexStr(str(hex(r^d)),8)
                #s=s[2:]
                w.append(str(s))
            #key_s=key_s+w[i]
        #key.append(key_s)
    ls=""
    key=[cipher_key]
    for i in range(1,11):
        ls=""
        for j in range(4):
            
            ls=ls+w[i*4+j]
           
        key.append(ls)
    return(key)
   # print("final key ::")
   # print(key)
    #print(len(key[0]))
    #print(len(w[32]))








def stateBlock(state):
    stater=len(state)
    statec=len(state[0])
    block="".join("".join(i[j] for i in state) for j in range(statec))
    return block

    

def blockState(block):
    elmntsz=2 #one byte contains two hexadecimal 
    stater=4
    statec=4
    statemat= [[block[elmntsz*(i+j*statec):elmntsz*(i+j*statec+1)] for j in range(statec)] for i in range(stater)]
    return statemat

def blockWord(block):#takes block string returns word's array
    wordsz=8 #total 32 bit 
    words=[block[i:(i+1)*wordsz] for i in range(0,len(block),wordsz)]
    return(words)

def wordBlock(words):#takes list of words return 
    block="".join(str(i) for i  in words)
    return(block)
    
def blockBytes(block):#takes block string returns word's array
    bytesz=2 #total 32 bit 
    bytesar=[block[i:i+bytesz] for i in range(0,len(block),bytesz)]
    return(bytesar)

def getBlockPt(pt):
    blocksz=32#
    while len(pt)%blocksz != 0:
        pt=pt+"0"
    blocks=[pt[i:i+blocksz]for i in range(0,len(pt),blocksz)]
    return (blocks)
    
def printstate(s):
    for i in s:
        print(i)
    print("")

if __name__=="__main__":
    main()