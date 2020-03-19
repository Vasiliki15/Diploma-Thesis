function [t, dt, e] = excitation_sel(sel)

    dt = 1e-9;
    t = (0:dt:35000e-12)'; % zoom into the transient phenomenon

%    e = zeros(length(t), 1);
    
    if (sel == 1)
        ref_t = 1*dt;
        width = 5;
        unitstep = and(t >= ref_t, t <= ref_t + width*dt);
        e = unitstep;
    elseif (sel == 2)
        ref_t = 1*dt;
        rise_t = 5*dt;
        unitstep = and(t >= ref_t, t <= ref_t+rise_t);
        ramp = t.*unitstep;
        ramp = ramp(ref_t/dt + 1:ref_t/dt + 1 + rise_t/dt) - ref_t;
        e = [zeros(ref_t/dt, 1); ramp; ramp(length(ramp)).*ones(length(t) - length(ramp) - ref_t/dt, 1)];
    else
        ref_t = 5*dt;
        delta = (t == ref_t);
        e = delta;
    end
    
end

