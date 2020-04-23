#ifndef PMVS3_OPTION_H
#define PMVS3_OPTION_H

#include <map>
#include <string>
#include <vector>

namespace PMVS3 {

struct Soption {
 public:
  int m_level;
  int m_csize;
  float m_threshold;
  int m_wsize;
  int m_minImageNum;
  int m_CPU;
  float m_setEdge;
  int m_useBound;
  int m_useVisData;
  int m_sequence;

  float m_maxAngleThreshold;
  float m_quadThreshold;

  std::string m_prefix;
  std::string m_option;

  /** \brief flag for target images
   *
   *     > 0: enumeration [id 1, id 2, ..., id n]
   *      -1: range specification [first id, last id]
   *  others: invalid
  */
  int m_tflag;

  /** \brief image ids */
  std::vector<int> m_timages;

  /** \brief flag for other images
   *
   *     >= 0: enumeration [id 1, id 2, ..., id n]
   *      -1: range specification [first id, last id]
   *      -2: vis.dat is used
   *      -3: not used
   *  others: invalid
  */
  int m_oflag;

  std::vector<int> m_oimages;

  /** \brief Dictionary for images ids
   *
   *    key: target image id
   *  value: index
  */
  std::map<int, int> m_dict;

  std::vector<int> m_bindexes;
  std::vector<std::vector<int> > m_visdata;
  std::vector<std::vector<int> > m_visdata2;

  Soption();

  void init(const std::string& prefix, const std::string& option);

 protected:
  void initOimages();
  void initBindexes(const std::string sbimages);
  void initVisdata();

  /** \brief Read vis.dat
   *
   *  Given m_timages and m_oimages, set m_visdata, m_visdata2
  */
  void initVisdata2();
};
};

#endif  // PMVS3_OPTION_H
