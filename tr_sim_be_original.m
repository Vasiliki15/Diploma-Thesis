% put E = C
% put A = G
% get e from the load_mtx.m
% dt is the timestep of simulation
% set x0 to a zero vector
% timestamps is the total number of time instants in the simulation


function [y] = tr_sim_be(E, A, B, D, e, dt, x0, timestamps)

    S = A + (1/dt)*E;
    
    [L,U] = lu(S);clc

    y = zeros(size(D,2), 35);

    x = x0;
   	
    tic;
    for k = 1:32
        
        
        
        b = (B*e(k, :)') + (1/dt)*E*x;

        c = L\b; 
        x = U\c;
        
        y(:, k) = D(:, k)'*x;
    end
    toc;

end

