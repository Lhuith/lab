function y = leap(year)

mod4 = mod(year, 4);
mod100 = mod(year, 100);
mod400 = mod(year, 400);

if (mod4 == 0)
    y = 'yes';
    if (mod100 == 0)
        y = 'no';
        if(mod400 == 0)
            y = 'yes';
        end
    end
else
    y = 'no';
end

end