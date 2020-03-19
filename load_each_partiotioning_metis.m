M=dlmread('n=48.txt');
n=288;
num_clusters=specified by user; %desired number of clusters
for i=1:n
    R(i,1)=R(i,1)+1;
end

P=zeros(n_origin,num_clusters);

for i=1:n
    j=M(i,1);
    P(i,j)=1;
end

%ftiaxnw Pi kai pinaka probolhs W
%Pm=P.';


W=P*inv(P.'*P);
V=P;
%exw susthma W*C*V*x'=-W*G*V*x'+W*B*u. To idio partitioning efarmozetai gia
%tous C, G kathws einai omoioi

C_ton_metis=W.'*C*P;
G_ton_metis=W.'*G*P;
B_ton_metis=W.'*B;
D_ton_metis=D.'*P;
