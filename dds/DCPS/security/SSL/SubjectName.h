/*
 * Distributed under the OpenDDS License.
 * See: http://www.OpenDDS.org/license.html
 */

#ifndef OPENDDS_SECURITY_SUBJECT_NAME_H
#define OPENDDS_SECURITY_SUBJECT_NAME_H

#include "dds/Versioned_Namespace.h"
#include "dds/DCPS/security/DdsSecurity_Export.h"

#include <string>
#include <map>

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace OpenDDS {
namespace Security {
namespace SSL {

  class DdsSecurity_Export SubjectName
  {
   public:
    SubjectName();
    SubjectName(const char*, bool permissive = false);
    SubjectName(const std::string&, bool permissive = false);

    /**
     * @return int 0 on success; 1 on failure.
     */
    int parse(const char*, bool permissive = false);

    /**
     * @return int 0 on success; 1 on failure.
     */
    int parse(const std::string&, bool permissive = false);

    bool operator==(const SubjectName&) const;
    bool operator!=(const SubjectName&) const;

   protected:
    /**
     * @return int 0 on success; 1 on failure.
     */
    int parse_permissive(const char*);

    /**
     * @return int 0 on success; 1 on failure.
     */
    int parse_dce(const char*);

    /**
     * @return int 0 on success; 1 on failure.
     */
    int parse_ldap_v3(const char*);

    int simple_avp_seq_parse(const char* in, const char* s_del,
                             const char* a_del, const char* s_trim,
                             const char* a_trim, bool push_back);

    typedef std::map<std::string, std::string> AttrMap;
    AttrMap map_;
  };

}  // namespace SSL
}  // namespace Security
}  // namespace OpenDDS

OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif
