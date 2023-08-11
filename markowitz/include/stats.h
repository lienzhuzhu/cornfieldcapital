#ifndef STATS_H
#define STATS_H

#include <Eigen/Dense>
#include <vector>
#include "Asset.h"


Eigen::MatrixXd compute_covariance_matrix(const std::vector<Asset>&);
double compute_covariance(const Asset&, const Asset&);


#endif // STATS_H
