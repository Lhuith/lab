from tinyec.ec import SubGroup, Curve

field = SubGroup(p=13, g=(0, 3), n=18, h=1)
curve = Curve(a=5, b=9, field=field, name='p1707')


print('curve:', curve)
for k in range(0, 25):
    p = k * curve.g
    print(f"{k} * G = ({p.x}, {p.y})")
