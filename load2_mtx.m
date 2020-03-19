load G.dat;
load C.dat;

load f_io.txt;

n = 288;



G = sparse( G(:,1), G(:,2), G(:,3), n, n );
C = sparse( C(:,1), C(:,2), C(:,3), n, n );
C_full=full(C);

N = length(f_io);

p = N/2;
q = p;

B = zeros(n, p);
D = zeros(n, q);
   
for in_i = 1:p
	B(f_io(2*in_i-1), in_i) = 1;
end
    
for out_i = 1:q
	D(f_io(2*out_i), out_i) = 1;
end



% Stimulus
%
[t, dt, e] = excitation_sel(1);
%
u = zeros(length(e), N/2);
%
for in_i = 1:p
    u(:, in_i) = e';
end
% 
timestamps = length(e);
%


