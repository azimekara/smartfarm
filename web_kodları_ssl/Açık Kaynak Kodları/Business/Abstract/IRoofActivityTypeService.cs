using Entities.Concrete;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Abstract
{
    public interface IRoofActivityTypeService
    {
        void Add(RoofActivityType roofActivityType);
        Task<List<RoofActivityType>> GetList();
    }
}
