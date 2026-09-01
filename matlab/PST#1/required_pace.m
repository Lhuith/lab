function pace = required_pace(time,distance)
    init = time./distance;
    h = init(1);
    h_return = floor(h);
    h_rem = h-h_return;
    
    m = init(2) + h_rem*60;
    m_return = floor(m);
    m_rem = m - m_return;
    
    s = init(3) + m_rem*60;
    
    pace = [h_return,m_return,s];
end