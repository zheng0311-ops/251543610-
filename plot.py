f=open("C:\\Users\\Nonep\\Desktop\\result.txt","r",encoding="ANSI")
is_find=False
words=[]
counts=[]
for line in f:
     line=line.strip()
     if"高频单词Top5:" in line:
         is_find=True
         continue
     if is_find and line!=" ":
        words_str,counts_str=line.split(":")
        words.append(words_str)
        counts.append(int(counts_str))       
f.close()
import matplotlib.pyplot as plt # type: ignore
plt.rcParams["font.sans-serif"]=["SimHei"]
plt.bar(words,counts,color=['red','orange','yellow','green','blue'])
plt.title("高频单词统计")
plt.xlabel("单词")
plt.ylabel("出现次数")
plt.savefig("top5.png")
plt.show()