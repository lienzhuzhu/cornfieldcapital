#ifndef STATS_H
#define STATS_H

#include <Eigen/Dense>
#include <vector>
#include "Asset.h"


Eigen::MatrixXd compute_covariance_matrix(std::vector<Asset>&);
double compute_covariance(Asset&, Asset&);


#endif // STATS_H
