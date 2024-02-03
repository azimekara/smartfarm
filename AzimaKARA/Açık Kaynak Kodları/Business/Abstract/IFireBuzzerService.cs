using Entities.Concrete;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Business.Abstract
{
    public interface IFireBuzzerService
    {
       Task<List<FireBuzzer>> GetAllData();
        Task<FireBuzzer> GetEndData();
        void Add(FireBuzzer fireBuzzer);
    }
}
