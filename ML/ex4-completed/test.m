y = [1,2,3,4,1,2,3,4];
num_labels =4;
yVectorized = zeros(size(y)(2), num_labels);
for i = 1:size(y)(2)
	for j = 1:num_labels
		if (y(i)==j)
			disp(j)
			yVectorized(i, j)=1;
			
		endif
	endfor
endfor