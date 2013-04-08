#include <Hubo_Control.h>

int main( int argc, char ** argv) {
  Hubo_Control hubo;
  
  Vector6d q;

  q << -20.0/180.0*M_PI, 0, 0, -M_PI/2+20.0/180.0*M_PI, -0.3, 0;

  hubo.setRightArmAngles( q, true);
 
}


// void huboArmJacobian(Eigen::MatrixXd &J, Vector6d &q, int side, const Eigen::Isometry3d &endEffector)
// {
//   Eigen::Vector3d ee,oi,di,zi;
//   Eigen::Isometry3d B;

//   huboArmTrans(B, q, side, endEffector, -1, 7);
//   ee = B(0:2,3);
//   for (int i = 0; i < 6; i++) {
//       huboArmTrans(B, q, side, endEffector, -1, i);
//       oi = B(0:2,3);
//       di = ee - oi;
//       zi = B(0:2,2);
//       J(0:2,i) = di.cross(zi);
//       J(3:5,i) = zi;
//   }
// }

// void huboArmTrans(Eigen::Isometry3d &B, Vector6d &q, int side,  const Eigen::Isometry3d &endEffector, int fromFrame, int toFrame)
// {
//     // Declarations
//     Eigen::Isometry3d neck, hand, T;
//     Eigen::MatrixXd limits(6,2);
//     Vector6d offset; offset.setZero();
    
//     // Parameters
//     double l1 = 214.5/1000.0;
//     double l2 = 179.14/1000.0;
//     double l3 = 181.59/1000.0;
//     double l4 = 4.75*25.4/1000.0;
    
//     Vector6d t, f, r, d;
//     t <<  M_PI/2, -M_PI/2,  M_PI/2,       0,       0,  M_PI/2;
//     f <<  M_PI/2,  M_PI/2, -M_PI/2,  M_PI/2, -M_PI/2,       0;
//     r <<       0,       0,       0,       0,       0,      l4;
//     d <<       0,       0,     -l2,       0,     -l3,       0;

//     limits <<
//         H_Arm_Ctrl[side].joint[0].pos_min, H_Arm_Ctrl[side].joint[0].pos_max,
//         H_Arm_Ctrl[side].joint[1].pos_min, H_Arm_Ctrl[side].joint[1].pos_max,
//         H_Arm_Ctrl[side].joint[2].pos_min, H_Arm_Ctrl[side].joint[2].pos_max,
//         H_Arm_Ctrl[side].joint[3].pos_min, H_Arm_Ctrl[side].joint[3].pos_max,
//         H_Arm_Ctrl[side].joint[4].pos_min, H_Arm_Ctrl[side].joint[4].pos_max,
//         H_Arm_Ctrl[side].joint[5].pos_min, H_Arm_Ctrl[side].joint[5].pos_max;

    
//     if (side == RIGHT) {
//         neck(0,0) = 1; neck(0,1) =  0; neck(0,2) = 0; neck(0,3) =   0;
//         neck(1,0) = 0; neck(1,1) =  0; neck(1,2) = 1; neck(1,3) = -l1;
//         neck(2,0) = 0; neck(2,1) = -1; neck(2,2) = 0; neck(2,3) =   0;
//         neck(3,0) = 0; neck(3,1) =  0; neck(3,2) = 0; neck(3,3) =   1;
        
// /*
//         limits <<
//         -2,   2,
//         -2,  .3,
//         -2,   2,
//         -2,   0.01,
//         -2,   2,
//         -1.4, 1.2;
// */        
//         // Set offsets
//         offset(1) = limits(1,1); // Note: I think this might be backwards
// //        offset(1) = -limits(1,1);
        
//     } else {
//         // Transformation from Neck frame to left shoulder pitch frame
//         neck(0,0) = 1; neck(0,1) =  0; neck(0,2) = 0; neck(0,3) =   0;
//         neck(1,0) = 0; neck(1,1) =  0; neck(1,2) = 1; neck(1,3) =  l1;
//         neck(2,0) = 0; neck(2,1) = -1; neck(2,2) = 0; neck(2,3) =   0;
//         neck(3,0) = 0; neck(3,1) =  0; neck(3,2) = 0; neck(3,3) =   1;
// /*        
//         limits <<
//         -2,   2,
//         -.3,   2,
//         -2,   2,
//         -2,   0.01,
//         -2,   2,
//         -1.4, 1.2;
// */        
//         // Set offsets
//         offset(1) = limits(1,0); // Note: I think this might be backwards
// //        offset(1) = -limits(1,0);
//     }
     
//     // Calculate forward kinematics
//     if (fromFrame == -1) {
//       B = neck;
//       fromFrame = 0;
//     } else {
//       B = Isometry3d:Identity();
//     }
//     for (int i = fromFrame; i < min(toFrame,6); i++) {
//         DH2HG(T, t(i)+q(i)-offset(i), f(i), r(i), d(i));
//         B = B*T;
//     }
//     if (fromFrame == 7) {
//       B = B*endEffector;
//     }
    
// }
