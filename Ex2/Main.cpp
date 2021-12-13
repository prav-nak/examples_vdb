#include <openvdb/openvdb.h>
#include <openvdb/tools/LevelSetSphere.h>
#include <openvdb/tools/Composite.h>
int main()
{
    openvdb::initialize();

    // Two grids of the same type containing level set volumes
    openvdb::FloatGrid::Ptr gridA = openvdb::tools::createLevelSetSphere<openvdb::FloatGrid>(
                /*radius=*/200.0, /*center=*/openvdb::Vec3f(0., 0., 0.),
                /*voxel size=*/4., /*width=*/8.0);
    openvdb::FloatGrid::Ptr gridB = openvdb::tools::createLevelSetSphere<openvdb::FloatGrid>(
                /*radius=*/200.0, /*center=*/openvdb::Vec3f(75., 75., 0.),
                /*voxel size=*/4., /*width=*/8.0);

    // Save copies of the two grids; CSG operations always modify
    // the A grid and leave the B grid empty.
    openvdb::FloatGrid::ConstPtr
        copyOfGridA = gridA->deepCopy(),
        copyOfGridB = gridB->deepCopy();
    // Compute the union (A u B) of the two level sets.
    openvdb::tools::csgIntersection(*gridA, *gridB);
    // Name the grid "LevelSetSphere".
    gridA->setName("LevelSetSphere");
    // Create a VDB file object and write out the grid.
    openvdb::io::File("intersection.vdb").write({gridA});
}