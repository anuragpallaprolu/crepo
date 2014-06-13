clear

gamma=0.5;

[k,l]=meshgrid(0:0.01:2.0,-2.0:0.01:2.0);

f=k.^2-gamma*(k.^2.0+l.^2.0).^(0.5);

contour(k,l,f,[0,0,0.5,1.0])