T=[0 1 0 0 0 5 0 0 0 0 0 0 0 0 0;
   1 0 2 0 0 0 6 0 0 0 0 0 0 0 0;
   0 2 0 3 0 0 0 7 0 0 0 0 0 0 0;
   0 0 2 0 4 0 0 0 8 0 0 0 0 0 0;
   0 0 0 3 0 0 0 0 0 9 0 0 0 0 0;
   5 0 0 0 0 0 6 0 0 0 10 0 0 0 0;
   0 6 0 0 0 5 0 7 0 0 0 11 0 0 0;
   0 0 2 0 0 0 6 0 8 0 0 0 12 0 0;
   0 0 0 3 0 0 0 7 0 9 0 0 0 13 0;
   0 0 0 0 4 0 0 0 8 0 0 0 0 0 14;
   0 0 0 0 0 5 0 0 0 0 0 11 0 0 0;
   0 0 0 0 0 6 0 0 0 10 0 12 0 0 0;
   0 0 0 0 0 0 0 7 0 0 0 11 0 13 0;
   0 0 0 0 0 0 0 0 8 0 0 0 12 0 14;
   0 0 0 0 0 0 0 0 0 9 0 0 0 13 0];
   


n=288;
Adj=zeros(1,1234);
Xad=zeros(1,289);

k=1;
m=2;
Xad(1)=0;

for i=1:n
    
    for j=1:n
        if C(i,j) ~= 0
            Adj(k)=j-1;
            k=k+1;
        end
        
    end
    Xad(m)=k-1;
    m=m+1;
end
            
%dlmwrite('Adjancy.txt',Adj); 
%dlmwrite('Xadj.txt',Xad);

nedjes=0;
for i=1:15
    for j=1:15
       if T(i,j)~=0
           nedjes=nedjes+1;
           
           T(j,i)=0;
       end
    end
end
    