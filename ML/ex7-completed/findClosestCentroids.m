function idx = findClosestCentroids(X, centroids)
%FINDCLOSESTCENTROIDS computes the centroid memberships for every example
%   idx = FINDCLOSESTCENTROIDS (X, centroids) returns the closest centroids
%   in idx for a dataset X where each row is a single example. idx = m x 1 
%   vector of centroid assignments (i.e. each entry in range [1..K])
%

% Set K
K = size(centroids, 1);

% You need to return the following variables correctly.
idx = zeros(size(X,1), 1);

% ====================== YOUR CODE HERE ======================
% Instructions: Go over every example, find its closest centroid, and store
%               the index inside idx at the appropriate location.
%               Concretely, idx(i) should contain the index of the centroid
%               closest to example i. Hence, it should be a value in the 
%               range 1..K
%
% Note: You can use a for-loop over the examples to compute this.
%
	


for i = 1:size(X,1)
	% fprintf('X(%d) = %d \n' , i, X(i));
	% size(X(i))
	% centroids(1)

	dist = sum((X(i,:) - centroids(1,:)).^2);
	% fprintf('initial dist: \t%d\n', dist);
	idx(i)=1;
	for j = 1:K
		% fprintf('X(%d): \t\t%f %f \n', i, X(i,:));
		% fprintf('centroids(%d): \t%f %f\n', j, centroids(j,:));
		distj = sum((X(i,:) - centroids(j,:)).^2);
		% fprintf('distj: \t\t%d \n', distj);
		% fprintf('dist: \t\t%d \n', dist);
		if(distj <= dist)
			% fprintf('Found min j: \t%d\n', j);
			idx(i)=j;
			dist=distj;
		endif
	endfor
endfor
% =============================================================

end

