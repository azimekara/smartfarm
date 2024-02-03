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
    public class FireBuzzerManager : IFireBuzzerService
    {
        private readonly IFireBuzzerDal _fireBuzzerDal;

        public FireBuzzerManager(IFireBuzzerDal fireBuzzerDal)
        {
            _fireBuzzerDal = fireBuzzerDal;
        }

        public void Add(FireBuzzer fireBuzzer)
        {
            _fireBuzzerDal.Insert(fireBuzzer);
        }

        public async Task<List<FireBuzzer>> GetAllData()
        {
           return await _fireBuzzerDal.GetList();
        }

        public async Task<FireBuzzer> GetEndData()
        {
            var data = await _fireBuzzerDal.GetList();
            return data.OrderByDescending(x => x.Id).FirstOrDefault();
        }
    }
}
