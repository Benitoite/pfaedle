// Copyright 2016, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Authors: Patrick Brosi <brosi@informatik.uni-freiburg.de>
#ifndef UTIL_GEO_GEON_H_
#define UTIL_GEO_GEON_H_

#define _USE_MATH_DEFINES

#include <math.h>
#include "util/Misc.h"
#include "util/geo/Point.h"

// -------------------
// Geometry stuff
// ------------------

namespace util {
namespace geon {

// convenience aliases

typedef Point<double> DPoint;
typedef Point<float> FPoint;
typedef Point<int> IPoint;

// typedef Line<double> DLine;
// typedef Line<float> FLine;
// typedef Line<int> ILine;

// typedef Box<double> DBox;
// typedef Box<float> FBox;
// typedef Box<int> IBox;

// typedef Polygon<double> DPolygon;
// typedef Polygon<float> FPolygon;
// typedef Polygon<int> IPolygon;

// _____________________________________________________________________________
// template <typename T>
// inline Line<T> rotate(const Line<T>& geo, double deg, const Point<T>& center) {
  // Line<T> ret;

  // bgeo::strategy::transform::translate_transformer<T, 2, 2> translate(
      // -center.getX(), -center.getY());
  // bgeo::strategy::transform::rotate_transformer<bgeo::degree, T, 2, 2> rotate(
      // deg);
  // bgeo::strategy::transform::translate_transformer<T, 2, 2> translateBack(
      // center.getX(), center.getY());

  // bgeo::strategy::transform::ublas_transformer<T, 2, 2> translateRotate(
      // prod(rotate.matrix(), translate.matrix()));
  // bgeo::strategy::transform::ublas_transformer<T, 2, 2> all(
      // prod(translateBack.matrix(), translateRotate.matrix()));

  // bgeo::transform(geo, ret, all);

  // return ret;
// }

// _____________________________________________________________________________
// template <typename T>
// inline MultiLine<T> rotate(const MultiLine<T>& geo, double deg,
                           // const Point<T>& center) {
  // MultiLine<T> ret;

  // bgeo::strategy::transform::translate_transformer<T, 2, 2> translate(
      // -center.getX(), -center.getY());
  // bgeo::strategy::transform::rotate_transformer<bgeo::degree, T, 2, 2> rotate(
      // deg);
  // bgeo::strategy::transform::translate_transformer<T, 2, 2> translateBack(
      // center.getX(), center.getY());

  // bgeo::strategy::transform::ublas_transformer<T, 2, 2> translateRotate(
      // prod(rotate.matrix(), translate.matrix()));
  // bgeo::strategy::transform::ublas_transformer<T, 2, 2> all(
      // prod(translateBack.matrix(), translateRotate.matrix()));

  // bgeo::transform(geo, ret, all);

  // return ret;
// }

// _____________________________________________________________________________
// template <typename T>
// inline Box<T> pad(const Box<T>& box, double padding) {
  // return Box<T>(Point<T>(box.min_corner().getX() - padding,
                         // box.min_corner().getY() - padding),
                // Point<T>(box.max_corner().getX() + padding,
                         // box.max_corner().getY() + padding));
// }

// _____________________________________________________________________________
template <typename T>
inline Point<T> rotate(const Point<T>& p, double deg) {
  return p;
}

// _____________________________________________________________________________
// template <typename T>
// inline Line<T> rotate(const Line<T>& geo, double deg) {
  // Point<T> center;
  // bgeo::centroid(geo, center);
  // return rotate(geo, deg, center);
// }

// _____________________________________________________________________________
// template <typename T>
// inline MultiLine<T> rotate(const MultiLine<T>& geo, double deg) {
  // Point<T> center;
  // bgeo::centroid(geo, center);
  // return rotate(geo, deg, center);
// }

// _____________________________________________________________________________
template <typename T>
inline Point<T> move(const Point<T>& geo, T x, T y) {
  return Point<T>(geo.getX() + x, geo.getY() + y);
}

// TODO: outfactor

// template <typename T>
// struct RotatedBox {
  // RotatedBox(const Box<T>& b, double rot, const Point<T>& center)
      // : b(b), rotateDeg(rot), center(center) {}
  // RotatedBox(const Box<T>& b, double rot) : b(b), rotateDeg(rot) {
    // bgeo::centroid(b, center);
  // }

  // Box<T> b;
  // double rotateDeg;
  // Point<T> center;

  // Polygon<T> getPolygon() {
    // Polygon<T> hull;
    // bgeo::convex_hull(b, hull);
    // return rotate(hull, rotateDeg, center);
  // }
// };

// _____________________________________________________________________________
template <typename T>
inline Box<T> minbox() {
  //return bgeo::make_inverse<Box<T>>();
}

// _____________________________________________________________________________
// template <typename T>
// inline RotatedBox<T> shrink(const RotatedBox<T>& b, double d) {
  // double xd =
      // b.b.max_corner().getX() - b.b.min_corner().getX();
  // double yd =
      // b.b.max_corner().getY() - b.b.min_corner().getY();

  // if (xd <= 2 * d) d = xd / 2 - 1;
  // if (yd <= 2 * d) d = yd / 2 - 1;

  // Box<T> r(Point<T>(b.b.min_corner().getX() + d,
                    // b.b.min_corner().getY() + d),
           // Point<T>(b.b.max_corner().getX() - d,
                    // b.b.max_corner().getY() - d));

  // return RotatedBox<T>(r, b.rotateDeg, b.center);
// }

// _____________________________________________________________________________
inline bool doubleEq(double a, double b) { return fabs(a - b) < 0.000001; }

// _____________________________________________________________________________
// template <typename Geometry, typename Box>
// inline bool contains(const Geometry& geom, const Box& box) {
  // return bgeo::within(geom, box);
// }

// _____________________________________________________________________________
// template <typename T>
// inline bool contains(const Point<T>& p1, const Point<T>& q1, const Point<T>& p2,
                     // const Point<T>& q2) {
  // Line<T> a, b;
  // a.push_back(p1);
  // a.push_back(q1);
  // b.push_back(p2);
  // b.push_back(q2);

  // return bgeo::covered_by(a, b);
// }

// _____________________________________________________________________________
// template <typename T>
// inline bool contains(T p1x, T p1y, T q1x, T q1y, T p2x, T p2y, T q2x, T q2y) {
  // Point<T> p1(p1x, p1y);
  // Point<T> q1(q1x, q1y);
  // Point<T> p2(p2x, p2y);
  // Point<T> q2(q2x, q2y);

  // return contains(p1, q1, p2, q2);
// }

// _____________________________________________________________________________
// template <typename T>
// inline bool intersects(const Point<T>& p1, const Point<T>& q1,
                       // const Point<T>& p2, const Point<T>& q2) {
  /*
   * checks whether two line segments intersect
   */
  // Line<T> a, b;
  // a.push_back(p1);
  // a.push_back(q1);
  // b.push_back(p2);
  // b.push_back(q2);

  // return !(contains(p1, q1, p2, q2) || contains(p2, q2, p1, q1)) &&
         // bgeo::intersects(a, b);
// }

// _____________________________________________________________________________
// template <typename T>
// inline bool intersects(T p1x, T p1y, T q1x, T q1y, T p2x, T p2y, T q2x, T q2y) {
  /*
   * checks whether two line segments intersect
   */
  // Point<T> p1(p1x, p1y);
  // Point<T> q1(q1x, q1y);
  // Point<T> p2(p2x, p2y);
  // Point<T> q2(q2x, q2y);

  // return intersects(p1, q1, p2, q2);
// }

// _____________________________________________________________________________
template <typename T>
inline Point<T> intersection(T p1x, T p1y, T q1x, T q1y, T p2x, T p2y, T q2x,
                             T q2y) {
  /*
   * calculates the intersection between two line segments
   */
  if (doubleEq(p1x, q1x) && doubleEq(p1y, q1y))
    return Point<T>(p1x, p1y);  // TODO: <-- intersecting with a point??
  if (doubleEq(p2x, q1x) && doubleEq(p2y, q1y)) return Point<T>(p2x, p2y);
  if (doubleEq(p2x, q2x) && doubleEq(p2y, q2y))
    return Point<T>(p2x, p2y);  // TODO: <-- intersecting with a point??
  if (doubleEq(p1x, q2x) && doubleEq(p1y, q2y)) return Point<T>(p1x, p1y);

  double a = ((q2y - p2y) * (q1x - p1x)) - ((q2x - p2x) * (q1y - p1y));
  double u = (((q2x - p2x) * (p1y - p2y)) - ((q2y - p2y) * (p1x - p2x))) / a;

  return Point<T>(p1x + (q1x - p1x) * u, p1y + (q1y - p1y) * u);
}

// _____________________________________________________________________________
template <typename T>
inline Point<T> intersection(const Point<T>& p1, const Point<T>& q1,
                             const Point<T>& p2, const Point<T>& q2) {
  /*
   * calculates the intersection between two line segments
   */
  return intersection(p1.getX(), p1.getY(),
                      q1.getX(), q1.getY(),
                      p2.getX(), p2.getY(),
                      q2.getX(), q2.getY());
}

// _____________________________________________________________________________
template <typename T>
inline bool lineIntersects(T p1x, T p1y, T q1x, T q1y, T p2x, T p2y, T q2x,
                           T q2y) {
  /*
   * checks whether two lines intersect
   */
  double EPSILON = 0.0000001;
  double a = ((q2y - p2y) * (q1x - p1x)) - ((q2x - p2x) * (q1y - p1y));

  return a > EPSILON || a < -EPSILON;
}

// _____________________________________________________________________________
template <typename T>
inline bool lineIntersects(const Point<T>& p1, const Point<T>& q1,
                           const Point<T>& p2, const Point<T>& q2) {
  /*
   * checks whether two lines intersect
   */
  return lineIntersects(p1.getX(), p1.getY(),
                        q1.getX(), q1.getY(),
                        p2.getX(), p2.getY(),
                        q2.getX(), q2.getY());
}

// _____________________________________________________________________________
inline double angBetween(double p1x, double p1y, double q1x, double q1y) {
  double dY = q1y - p1y;
  double dX = q1x - p1x;
  return atan2(dY, dX);
}

// _____________________________________________________________________________
template <typename T>
inline double angBetween(const Point<T>& p1, const Point<T>& q1) {
  return angBetween(p1.getX(), p1.getY(),
                    q1.getX(), q1.getY());
}

// _____________________________________________________________________________
inline double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// _____________________________________________________________________________
inline double innerProd(double x1, double y1, double x2, double y2, double x3,
                        double y3) {
  double dx21 = x2 - x1;
  double dx31 = x3 - x1;
  double dy21 = y2 - y1;
  double dy31 = y3 - y1;
  double m12 = sqrt(dx21 * dx21 + dy21 * dy21);
  double m13 = sqrt(dx31 * dx31 + dy31 * dy31);
  double theta = acos(std::min((dx21 * dx31 + dy21 * dy31) / (m12 * m13), 1.0));

  return theta * (180 / M_PI);
}

// _____________________________________________________________________________
template <typename T>
inline double innerProd(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
  return innerProd(a.template getX(), a.template getY(),
                   b.template getX(), b.template getY(),
                   c.template getX(), c.template getY());
}

// _____________________________________________________________________________
template <typename T>
inline double dist(const Point<T>& p1, const Point<T>& p2) {
  return 0;  // TODo
}

// _____________________________________________________________________________
template <typename T>
inline std::string getWKT(const Point<T>* p) {
  std::stringstream ss;
  // TODO
  return ss.str();
}

// _____________________________________________________________________________
template <typename T>
inline double len(const Point<T>& g) {
  return 0;
}

// _____________________________________________________________________________
template <typename T>
inline Point<T> simplify(const Point<T>& g, double d) {
  return g;
}

// _____________________________________________________________________________
inline double distToSegment(double lax, double lay, double lbx, double lby,
                            double px, double py) {
  double d = dist(lax, lay, lbx, lby) * dist(lax, lay, lbx, lby);
  if (d == 0) return dist(px, py, lax, lay);

  double t = ((px - lax) * (lbx - lax) + (py - lay) * (lby - lay)) / d;

  if (t < 0) {
    return dist(px, py, lax, lay);
  } else if (t > 1) {
    return dist(px, py, lbx, lby);
  }

  return dist(px, py, lax + t * (lbx - lax), lay + t * (lby - lay));
}

// _____________________________________________________________________________
template <typename T>
inline double distToSegment(const Point<T>& la, const Point<T>& lb,
                            const Point<T>& p) {
  return distToSegment(la.getX(), la.getY(),
                       lb.getX(), lb.getY(),
                       p.getX(), p.getY());
}

// _____________________________________________________________________________
template <typename T>
inline Point<T> projectOn(const Point<T>& a, const Point<T>& b,
                          const Point<T>& c) {
  if (doubleEq(a.getX(), b.getX()) &&
      doubleEq(a.getY(), b.getY()))
    return a;
  if (doubleEq(a.getX(), c.getX()) &&
      doubleEq(a.getY(), c.getY()))
    return a;
  if (doubleEq(b.getX(), c.getX()) &&
      doubleEq(b.getY(), c.getY()))
    return b;

  double x, y;

  if (c.getX() == a.getX()) {
    // infinite slope
    x = a.getX();
    y = b.getY();
  } else {
    double m = (double)(c.getY() - a.getY()) /
               (c.getX() - a.getX());
    double bb = (double)a.getY() - (m * a.getX());

    x = (m * b.getY() + b.getX() - m * bb) / (m * m + 1);
    y = (m * m * b.getY() + m * b.getX() + bb) /
        (m * m + 1);
  }

  Point<T> ret = Point<T>(x, y);

  bool isBetween = dist(a, c) > dist(a, ret) && dist(a, c) > dist(c, ret);
  bool nearer = dist(a, ret) < dist(c, ret);

  if (!isBetween) return nearer ? a : c;

  return ret;
}

// _____________________________________________________________________________
template <typename T>
inline double parallelity(const Box<T>& box, const Line<T>& line) {
  double ret = M_PI;

  double a = angBetween(box.min_corner(),
                        Point<T>(box.min_corner().getX(),
                                 box.max_corner().getY()));
  double b = angBetween(box.min_corner(),
                        Point<T>(box.max_corner().getX(),
                                 box.min_corner().getY()));
  double c = angBetween(box.max_corner(),
                        Point<T>(box.min_corner().getX(),
                                 box.max_corner().getY()));
  double d = angBetween(box.max_corner(),
                        Point<T>(box.max_corner().getX(),
                                 box.min_corner().getY()));

  double e = angBetween(line.front(), line.back());

  double vals[] = {a, b, c, d};

  for (double ang : vals) {
    double v = fabs(ang - e);
    if (v > M_PI) v = 2 * M_PI - v;
    if (v > M_PI / 2) v = M_PI - v;
    if (v < ret) ret = v;
  }

  return 1 - (ret / (M_PI / 4));
}

// _____________________________________________________________________________
// template <typename T>
// inline double parallelity(const Box<T>& box, const MultiLine<T>& multiline) {
  // double ret = 0;
  // for (const Line<T>& l : multiline) {
    // ret += parallelity(box, l);
  // }

  // return ret / multiline.size();
// }

// _____________________________________________________________________________
// template <typename GeomA, typename GeomB>
// inline bool intersects(const GeomA& a, const GeomB& b) {
  // return bgeo::intersects(a, b);
// }

// _____________________________________________________________________________
// template <typename T, template <typename> typename Geometry>
// inline RotatedBox<T> getOrientedEnvelope(Geometry<T> pol) {
  // // TODO: implement this nicer, works for now, but inefficient
  // // see
  // // https://geidav.wordpress.com/tag/gift-wrapping/#fn-1057-FreemanShapira1975
  // // for a nicer algorithm

  // Point<T> center;
  // bgeo::centroid(pol, center);

  // Box<T> tmpBox = getBoundingBox(pol);
  // double rotateDeg = 0;

  // // rotate in 5 deg steps
  // for (int i = 1; i < 360; i += 1) {
    // pol = rotate(pol, 1, center);
    // Box<T> e;
    // bgeo::envelope(pol, e);
    // if (bgeo::area(tmpBox) > bgeo::area(e)) {
      // tmpBox = e;
      // rotateDeg = i;
    // }
  // }

  // return RotatedBox<T>(tmpBox, -rotateDeg, center);
// }

// _____________________________________________________________________________
template <typename T>
// inline Box<T> getBoundingBox(Point<T> pol) {
  // Box<T> tmpBox;
  // bgeo::envelope(pol, tmpBox);
  // return tmpBox;
// }

// _____________________________________________________________________________
// template <typename T>
// inline Box<T> extendBox(const Box<T>& a, Box<T> b) {
  // bgeo::expand(b, a);
  // return b;
// }

// _____________________________________________________________________________
template <typename G, typename T>
inline Box<T> extendBox(G pol, Box<T> b) {
  Box<T> tmp;
  bgeo::envelope(pol, tmp);
  bgeo::expand(b, tmp);
  return b;
}

// _____________________________________________________________________________
// template <typename T>
// inline double commonArea(const Box<T>& ba, const Box<T>& bb) {
  // T l = std::max(ba.min_corner().getX(),
                 // bb.min_corner().getX());
  // T r = std::min(ba.max_corner().getX(),
                 // bb.max_corner().getX());
  // T b = std::max(ba.min_corner().getY(),
                 // bb.min_corner().getY());
  // T t = std::min(ba.max_corner().getY(),
                 // bb.max_corner().getY());

  // if (l > r || b > t) return 0;

  // return (r - l) * (t - b);
// }

// _____________________________________________________________________________
// template <typename T, template <typename> typename Geometry>
// inline RotatedBox<T> getFullEnvelope(Geometry<T> pol) {
  // Point<T> center;
  // bgeo::centroid(pol, center);

  // Box<T> tmpBox;
  // bgeo::envelope(pol, tmpBox);
  // double rotateDeg = 0;

  // MultiPolygon<T> ml;

  // // rotate in 5 deg steps
  // for (int i = 1; i < 360; i += 1) {
    // pol = rotate(pol, 1, center);
    // Polygon<T> hull;
    // bgeo::convex_hull(pol, hull);
    // ml.push_back(hull);
    // Box<T> e;
    // bgeo::envelope(pol, e);
    // if (bgeo::area(tmpBox) > bgeo::area(e)) {
      // tmpBox = e;
      // rotateDeg = i;
    // }
  // }

  // bgeo::envelope(ml, tmpBox);

  // return RotatedBox<T>(tmpBox, rotateDeg, center);
// }

// _____________________________________________________________________________
// template <typename T>
// inline RotatedBox<T> getOrientedEnvelopeAvg(MultiLine<T> ml) {
  // MultiLine<T> orig = ml;
  // // get oriented envelope for hull
  // RotatedBox<T> rbox = getFullEnvelope<T>(ml);
  // Point<T> center;
  // bgeo::centroid(rbox.b, center);

  // ml = rotate(ml, -rbox.rotateDeg - 45, center);

  // double bestDeg = -45;
  // double score = parallelity(rbox.b, ml);

  // for (double i = -45; i <= 45; i += .5) {
    // ml = rotate(ml, -.5, center);
    // double p = parallelity(rbox.b, ml);
    // if (parallelity(rbox.b, ml) > score) {
      // bestDeg = i;
      // score = p;
    // }
  // }

  // rbox.rotateDeg += bestDeg;

  // // move the box along 45deg angles from its origin until it fits the ml
  // // = until the intersection of its hull and the box is largest
  // Polygon<T> p = rbox.getPolygon();
  // p = rotate(p, -rbox.rotateDeg, rbox.center);

  // Polygon<T> hull;
  // bgeo::convex_hull(orig, hull);
  // hull = rotate(hull, -rbox.rotateDeg, rbox.center);

  // Box<T> box;
  // bgeo::envelope(hull, box);
  // rbox = RotatedBox<T>(box, rbox.rotateDeg, rbox.center);

  // return rbox;
// }

// _____________________________________________________________________________
template <typename T>
inline Line<T> densify(const Line<T>& l, double d) {
  if (!l.size()) return l;

  Line<T> ret;
  ret.reserve(l.size());
  ret.push_back(l.front());

  for (size_t i = 1; i < l.size(); i++) {
    double segd = dist(l[i-1], l[i]);
    double dx =
        (l[i].getX() - l[i-1].getX()) / segd;
    double dy =
        (l[i].getY() - l[i-1].getY()) / segd;
    double curd = d;
    while (curd < segd) {
      ret.push_back(Point<T>(l[i-1].getX() + dx * curd,
                             l[i-1].getY() + dy * curd));
      curd += d;
    }

    ret.push_back(l[i]);
  }

  return ret;
}

// _____________________________________________________________________________
template <typename T>
inline double frechetDistC(size_t i, size_t j, const Line<T>& p,
                           const Line<T>& q,
                           std::vector<std::vector<double>>& ca) {
  // based on Eiter / Mannila
  // http://www.kr.tuwien.ac.at/staff/eiter/et-archive/cdtr9464.pdf

  if (ca[i][j] > -1)
    return ca[i][j];
  else if (i == 0 && j == 0)
    ca[i][j] = dist(p[0], q[0]);
  else if (i > 0 && j == 0)
    ca[i][j] = std::max(frechetDistC(i - 1, 0, p, q, ca), dist(p[i], q[0]));
  else if (i == 0 && j > 0)
    ca[i][j] = std::max(frechetDistC(0, j - 1, p, q, ca), dist(p[0], q[j]));
  else if (i > 0 && j > 0)
    ca[i][j] = std::max(std::min(std::min(frechetDistC(i - 1, j, p, q, ca),
                                          frechetDistC(i - 1, j - 1, p, q, ca)),
                                 frechetDistC(i, j - 1, p, q, ca)),
                        dist(p[i], q[j]));
  else
    ca[i][j] = std::numeric_limits<double>::infinity();

  return ca[i][j];
}

// _____________________________________________________________________________
template <typename T>
inline double frechetDist(const Line<T>& a, const Line<T>& b, double d) {
  // based on Eiter / Mannila
  // http://www.kr.tuwien.ac.at/staff/eiter/et-archive/cdtr9464.pdf

  auto p = densify(a, d);
  auto q = densify(b, d);

  std::vector<std::vector<double>> ca(p.size(),
                                      std::vector<double>(q.size(), -1.0));
  double fd = frechetDistC(p.size() - 1, q.size() - 1, p, q, ca);

  return fd;
}

// _____________________________________________________________________________
template <typename T>
inline double accFrechetDistC(const Line<T>& a, const Line<T>& b, double d) {

  auto p = densify(a, d);
  auto q = densify(b, d);

  std::vector<std::vector<double>> ca(p.size(),
                                        std::vector<double>(q.size(), 0));

  for (size_t i = 0; i < p.size(); i++) ca[i][0] = std::numeric_limits<double>::infinity();
  for (size_t j = 0; j < q.size(); j++) ca[0][j] = std::numeric_limits<double>::infinity();
  ca[0][0] = 0;

  for (size_t i = 1; i < p.size(); i++) {
    for (size_t j = 1; j < q.size(); j++) {
      double d = util::geo::dist(p[i], q[j]) * util::geo::dist(p[i], p[i-1]);
      ca[i][j] = d + std::min(ca[i-1][j], std::min(ca[i][j-1], ca[i-1][j-1]));
    }
  }

  return ca[p.size() - 1][q.size() - 1];
}



// _____________________________________________________________________________
template <typename T>
inline Point<T> latLngToWebMerc(double lat, double lng) {
  double x = 6378137.0 * lng * 0.017453292519943295;
  double a = lat * 0.017453292519943295;

  double y = 3189068.5 * log((1.0 + sin(a)) / (1.0 - sin(a)));
  return Point<T>(x, y);
}

// _____________________________________________________________________________
template <typename T>
inline Point<T> webMercToLatLng(double x, double y) {
  double lat = 114.591559026 * (atan(exp(y / 6378137.0)) - 0.78539825);
  double lon = x / 111319.4907932735677;
  return Point<T>(lon, lat);
}

// _____________________________________________________________________________
template <typename G1, typename G2>
inline double webMercMeterDist(const G1& a, const G2& b) {
  // euclidean distance on web mercator is in meters on equator,
  // and proportional to cos(lat) in both y directions

  double latA = 2 * atan(exp(a.getY() / 6378137.0)) - 1.5707965;
  double latB = 2 * atan(exp(b.getY() / 6378137.0)) - 1.5707965;

  return util::geo::dist(a, b) * cos((latA + latB) / 2.0);
}
}
}

#endif  // UTIL_GEO_GEON_H_
