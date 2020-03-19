
%system: C_ton*x'=-G_ton*x'+B_ton*u. 
%for H(30,30);
m=logspace(2,6,100);
for i=1:100

    s=j*m(d);
    H_red=(abs((B_ton')*inv((s*C_ton+G_ton))*B_ton));
    H_red_db(:,i)=mag2db(abs(H_red(30,30)));
    H=(abs((B')*inv((s*C+G))*B));
    H_db(:,i)=mag2db(abs(H(30,30)));
end


figure('Name','Reduced and Original Model Comparison');');
plot(m,H_red_db,'r');
hold on;
plot(m,H_db,'b');



