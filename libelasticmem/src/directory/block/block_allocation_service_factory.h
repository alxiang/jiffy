#ifndef ELASTICMEM_BLOCK_ALLOCATION_SERVICE_FACTORY_H
#define ELASTICMEM_BLOCK_ALLOCATION_SERVICE_FACTORY_H

#include "block_allocation_service.h"
#include "block_allocator.h"

namespace elasticmem {
namespace directory {

class block_allocation_service_factory : public block_allocation_serviceIfFactory {
 public:
  explicit block_allocation_service_factory(std::shared_ptr<block_allocator> alloc);
 private:
  block_allocation_serviceIf *getHandler(const ::apache::thrift::TConnectionInfo &connInfo) override;
  void releaseHandler(block_allocation_serviceIf *anIf) override;

 private:
  std::shared_ptr<block_allocator> alloc_;
};

}
}

#endif //ELASTICMEM_BLOCK_ALLOCATION_SERVICE_FACTORY_H