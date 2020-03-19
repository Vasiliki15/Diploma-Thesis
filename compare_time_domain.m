%analush xronou
n=48;
x0_red=zeros(n,1);
x0=zeros(288,1);

y_red=tr_sim_be_original(C_ton_metis, G_ton_metis, B_ton_metis, D_ton_metis', e, dt, x0, timestamps);
y = tr_sim_be_original(C, G, B, B, e, dt, x0_288, timestamps);

%plot for i=20
figure('Name','Reduced and original model comparison in time domain'););
xlabel('Time Instants');
ylabel('Output y');
plot(y_red(20,:),'r');
hold on;
plot(y(20,:),'b');
    
%eisodoi
figure('Name','Input 1 '); 
plot(u(:,1));

