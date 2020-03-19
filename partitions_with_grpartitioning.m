%n=number of partiotions 
n=24;
n_origin=288;

%partitioning C to V,VT
[ndx,Pi,cost]= grPartition(C,n,1);
for i=1:n_origin
    k=ndx(i,1);
    P(i,k)=1;
end

%briskw pinakes W=VT kai V=Pi

W=P*inv(P.'*P);

%system: W*C*V*x'=-W*G*V*x'+W*B*u.
C_ton=W.'*C*Pi;
G_ton=W.'*G*Pi;
B_ton=W.'*B;
%D_ton=(P.')*B;
D_ton=(B.')*P;