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
    public class RoofActivityManager : IRoofActivityService
    {
        private readonly IRoofActivityDal _roofActivityDal;

        public RoofActivityManager(IRoofActivityDal roofActivityDal)
        {
            _roofActivityDal = roofActivityDal;
        }

        public void AddActivity(RoofActivity roofActivity)
        {
            
            _roofActivityDal.Insert(roofActivity);
        }

        public async Task<RoofActivity> GetEndActivity()
        {
            var endData = await _roofActivityDal.GetList();
            return endData.OrderByDescending(x => x.Id).FirstOrDefault();
             
        }

        public async Task<List<RoofActivity>> GetRoofActivities()
        {
            return await _roofActivityDal.GetList();
        }
    }
}
