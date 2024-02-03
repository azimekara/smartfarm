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
    public class DoorActivityManager : IDoorActivityService
    {
        private readonly IDoorActivityDal _doorActivityDal;

        public DoorActivityManager(IDoorActivityDal doorActivityDal)
        {
            _doorActivityDal = doorActivityDal;
        }

        public void AddActivity(DoorActivity doorActivity)
        {
            _doorActivityDal.Insert(doorActivity);
        }

        public async Task<DoorActivity> GetEndActivity()
        {
            var data = await _doorActivityDal.GetList();
            return data.OrderByDescending(x => x.Id).FirstOrDefault();

        }
    }
}
