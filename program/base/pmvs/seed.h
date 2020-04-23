#ifndef PMVS3_SEED_H
#define PMVS3_SEED_H

#include <boost/shared_ptr.hpp>
#include <vector>
#include "patch.h"
#include "point.h"

#include "tinycthread.h"

namespace PMVS3 {
class CfindMatch;

using Ppoint = boost::shared_ptr<Cpoint>;

class Cseed {
 public:
  Cseed(CfindMatch& findMatch);
  virtual ~Cseed(){};

  /** \brief TODO
   *
   *  @param[in]
  */
  void init(const std::vector<std::vector<Cpoint> >& points);

  /** \brief TODO
   *
   *  @param[in]
  */
  void run();

  void clear();

 protected:
  /** \brief TODO
   *
   *  @param[in]
  */
  void readPoints(const std::vector<std::vector<Cpoint> >& points);

  /** \brief TODO
   *
   *  @param[in] index -
   *  @param[in] x     -
   *  @param[in] y     -
   *  @return
  */
  int canAdd(const int index, const int x, const int y);

  /** \brief TODO
   *
   *  @param[in] index -
   *  @param[in] id    -
  */
  void initialMatch(const int index, const int id);

  /** \brief TODO
   *
   *  @param[in]
  */
  void collectCells(const int index0, const int index1, const Cpoint& p0,
                    std::vector<Vec2i>& cells);

  /** \brief TODO
   *
   *  @param[in]
  */
  void collectCandidates(const int index, const std::vector<int>& indexes,
                         const Cpoint& point, std::vector<Ppoint>& vcp);

  /** \brief
   *
   *  starting with (index, indexs), set visible images by looking at
   *  correlation.
   *
   *  @param[in]
  */
  int initialMatchSub(const int index0, const int index1, const int id,
                      Patch::Cpatch& patch);

  /** \brief TODO
   *
   *  @param[in]
  */
  void unproject(const int index0, const int index1, const Cpoint& p0,
                 const Cpoint& p1, Vec4f& coord) const;

  //----------------------------------------------------------------------
  CfindMatch& m_fm;
  // points in a grid. For each index, grid
  std::vector<std::vector<std::vector<Ppoint> > > m_ppoints;

  //----------------------------------------------------------------------
  // thread related
  //----------------------------------------------------------------------
  /** \brief TODO
   *
   *  @param[in]
  */
  void initialMatchThread();

  /** \brief Start a thread for initial matching
   *
   *  @param[in] arg - current class
  */
  static int initialMatchThreadTmp(void* arg);

  // Number of trials
  std::vector<int> m_scounts;
  // Number of failures in the prep
  std::vector<int> m_fcounts0;
  // Number of failures in the post processing
  std::vector<int> m_fcounts1;
  // Number passes
  std::vector<int> m_pcounts;
};

}  // PMVS3

#endif  // PMVS3_SEED_H
