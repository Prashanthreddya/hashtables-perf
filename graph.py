import matplotlib.pyplot as plt
#store the no of entries in list 'x'
x=[0,10,50,100,500,1000,5000,10000,50000,100000]


#store the search time taken by 3 diff hashtables in 3 diff lists 'h1','h2','h3' respectively
h1=[0,18,20,22,24,42,82,95,401,739]
h2=[0,9,12,13,18,20,45,153,555,1487]
h3=[0,7,10,12,12,12,43,51,335,732]


#store the search time taken by array of structures 'array'
arr=[0,26,31,33,76,142,527,785,4975,7704]


#Assign title,x and y label to the graph
plt.title("Search Performance of Hashtables 'h1','h2','h3' vs Array of Structures 'arr'")
plt.xlabel("No of Entries", fontsize=13, color='k')
plt.ylabel("Time in Us",fontsize=13, color='k')


#plot 4 graphs on the same plot
plt.plot(x,arr,linewidth=3.5)
plt.plot(x,h1,linewidth=1.5)
plt.plot(x,h2,linewidth=1.5)
plt.plot(x,h3,linewidth=1.5)


#naming the graphs in the plot
plt.legend(['Array of Structures', 'Hashtable 1', 'Hashtable 2', 'Hashtable 3'],fontsize='13', loc='upper left')


#display the graph
plt.show()
