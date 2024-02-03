using Business.Abstract;
using DataAccess.Abstract;
using Entities.Concrete;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Concrete
{
    public class RoofActivityTypeManager : IRoofActivityTypeService
    {
        private readonly IRoofActivityTypeDal _roofActivityTypeDal;

        public RoofActivityTypeManager(IRoofActivityTypeDal roofActivityTypeDal)
        {
            _roofActivityTypeDal = roofActivityTypeDal;
        }

        public void Add(RoofActivityType roofActivityType)
        {
            _roofActivityTypeDal.Insert(roofActivityType);
        }

        public Task<List<RoofActivityType>> GetList()
        {
            return _roofActivityTypeDal.GetList();
        }
    }
}
