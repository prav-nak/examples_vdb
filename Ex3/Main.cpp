#include <openvdb/openvdb.h>
#include <openvdb/tools/LevelSetSphere.h>
int main()
{
    openvdb::initialize();
    // Create a FloatGrid and populate it with a narrow-band
    // signed distance field of a sphere.
    openvdb::FloatGrid::Ptr grid =
        openvdb::tools::createLevelSetSphere<openvdb::FloatGrid>(
            /*radius=*/200.0, /*center=*/openvdb::Vec3f(0., 0., 0.),
            /*voxel size=*/4., /*width=*/8.0);
    // Associate some metadata with the grid.
    grid->insertMeta("radius", openvdb::FloatMetadata(50.0));
    // Name the grid "LevelSetSphere".
    grid->setName("LevelSetSphere");
    // Create a VDB file object and write out the grid.
    openvdb::io::File("mygrids.vdb").write({grid});
}