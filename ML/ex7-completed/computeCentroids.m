function centroids = computeCentroids(X, colors, K)
%COMPUTECENTROIDS returs the new centroids by computing the means of the 
%data points assigned to each centroid.
%   centroids = COMPUTECENTROIDS(X, colors, K) returns the new centroids by 
%   computing the means of the data points assigned to each centroid. It is
%   given a dataset X where each row is a single data point, a vector
%   colors of centroid assignments (i.e. each entry in range [1..K]) for each
%   example, and K, the number of centroids. You should return a matrix
%   centroids, where each row of centroids is the mean of the data points
%   assigned to it.
%

% Useful variables
[m n] = size(X);

% You need to return the following variables correctly.
centroids = zeros(K, n);


% ====================== YOUR CODE HERE ======================
% Instructions: Go over every centroid and compute mean of all points that
%               belong to it. Concretely, the row vector centroids(i, :)
%               should contain the mean of the data points assigned to
%               centroid i.
%
% Note: You can use a for-loop over the centroids to compute this.
%

for centroidIndex=1:K
	count = 0;
	sumX=zeros(1, n);
	for trainingExampleNumber = 1:m
		% colors(trainingExampleNumber)
		if(colors(trainingExampleNumber) == centroidIndex )
			count++;
			sumX += X(trainingExampleNumber,:);
		endif
		if(count>0)
			centroids(centroidIndex,:)=sumX/count;
		endif
	endfor
endfor		







% =============================================================


end

