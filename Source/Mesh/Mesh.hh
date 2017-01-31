/******************************************************************************

  This source file is part of the Delaunay project.

  Copyright T.J. Corona

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/

#ifndef DELAUNAY_MESH_MESH_HH
#define DELAUNAY_MESH_MESH_HH

#include <vector>

#include "Mesh/Vertex.hh"
#include "Mesh/Edge.hh"
#include "Mesh/Triangle.hh"
#include "Mesh/Polygon.hh"

namespace Delaunay
{
namespace Mesh
{
class Mesher;

class Mesh
{
public:
  typedef Delaunay::Shape::Polygon Polygon;
  typedef std::set<const Polygon>  InteriorBoundarySet;
  typedef std::set<const Vertex>   VertexSet;
  typedef std::set<const Edge>     EdgeSet;
  typedef std::set<const Triangle> TriangleSet;

  friend class Mesher;

  Mesh() : Perimeter(Shape::PointVector()) {}
  virtual ~Mesh() {}

  const Polygon&     GetPerimeter() const { return this->Perimeter; }
  const InteriorBoundarySet&
            GetInteriorBoundaries() const { return this->InteriorBoundaries; }
  const VertexSet&   GetVertices()  const { return this->Vertices;  }
  const EdgeSet&     GetEdges()     const { return this->Edges;     }
  const TriangleSet& GetTriangles() const { return this->Triangles; }

protected:
  Polygon             Perimeter;
  InteriorBoundarySet InteriorBoundaries;
  VertexSet           Vertices;
  EdgeSet             Edges;
  TriangleSet         Triangles;
};

}
}

#endif