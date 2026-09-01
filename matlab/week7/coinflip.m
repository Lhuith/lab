function side = coinflip()
    flip = randi(2)-1;
    
    if flip >= 0.5 
      side = "heads";
    else
      side = "tails";
    end
            
end